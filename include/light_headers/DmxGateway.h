#ifndef DMXGATEWAY_H
#define DMXGATEWAY_H
#include <ola/io/SelectServer.h>
#include <ola/Logging.h> // снова перепроверить все заголовочные файлы
#include <ola/client/ClientWrapper.h>
#include <ola/thread/Thread.h>
#include <ola/Callback.h>

#include <ola/DmxBuffer.h>
#include <vector>

class DmxGateway : public ola::thread::Thread {
public:
    DmxGateway() = delete;

    DmxGateway(unsigned int universe_amount) : dmx_data_(universe_amount), universe_amount_(universe_amount) {
        for (int i = 0; i < universe_amount_; ++i) {
            dmx_data_[i].Blackout();
        }
    }

    bool Start() {
        if (!wrapper_.Setup()) {
            OLA_FATAL << "DmxGateway::Start() failed";
            return false;
        }

        GatewaySetup();

        return ola::thread::Thread::Start();
    }

    void Stop() {
        select_server_->Terminate();
    }

    ola::DmxBuffer& GetBuffer(unsigned int universe_id) {
        return dmx_data_[universe_id];
    }

protected:
    void *Run() {
        OLA_INFO << "DmxGateway::Run() run the thread";
        select_server_->Run();
        return NULL;
    }

private:
    void GatewaySetup() {
        ola_client_ = wrapper_.GetClient(); // getclient константный метод, а я присваиваю неконстантному указателю
        select_server_ = wrapper_.GetSelectServer();

        // ola::Callback0<bool> callback2 = ola::NewCallback(this, &DmxGateway::SendData);
        select_server_->RegisterRepeatingTimeout(ola_30_fps_, ola::NewCallback(this, &DmxGateway::SendData)); // create a constant for that! // Use the version that takes a TimeInterval instead.

        ola_client_->SetCloseHandler(ola::NewSingleCallback(this, &DmxGateway::ConnectionClosed));
        OLA_INFO << "DmxGateway was succesfully created with callback 30 fps";
    }

    void ConnectionClosed() {
        OLA_FATAL << "Connection to olad was closed";
        select_server_->Terminate();
    }

    // Returning false from the callback will cause it to be cancelled.
    bool SendData() {
        OLA_FATAL << "send data";
        for (unsigned int curr_univ = 0; curr_univ < universe_amount_; ++curr_univ) {
            ola_client_->SendDMX(curr_univ, dmx_data_[curr_univ], casual_dmx_args_);
        }
        return true;
    }



    std::vector <ola::DmxBuffer> dmx_data_;
    unsigned int universe_amount_; // нужно ли здесь хранить количество вселенных?
    const ola::client::SendDMXArgs casual_dmx_args_ = ola::client::SendDMXArgs();

    ola::client::OlaClientWrapper wrapper_;
    ola::io::SelectServer* select_server_ = nullptr;
    ola::client::OlaClient* ola_client_ = nullptr;

    const ola::TimeInterval ola_second_ = ola::TimeInterval(1000000);
    const ola::TimeInterval ola_30_fps_ = ola::TimeInterval(33333); // not 30 fps, but 30.003...
};

#endif // DMXGATEWAY_H
