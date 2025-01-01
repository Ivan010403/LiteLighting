#ifndef DMXGATEWAY_H
#define DMXGATEWAY_H
#include <ola/Callback.h>
#include <ola/client/ClientWrapper.h>
#include <ola/DmxBuffer.h>
#include <vector>
#include <ola/Logging.h> // снова перепроверить все заголовочные файлы

class DmxGateway {
public:
    DmxGateway() = delete;

    DmxGateway(unsigned int universe_amount) : dmx_data_(universe_amount), universe_amount_(universe_amount) {
        ola::InitLogging(ola::OLA_LOG_INFO, ola::OLA_LOG_STDERR);

        if (!wrapper_.Setup()) {
            OLA_FATAL << "OlaClientWrapper setup failed";
            exit(1);
        }

        ola_client_ = wrapper_.GetClient();
        select_server_ = wrapper_.GetSelectServer();

        // ola::Callback0<bool> callback2 = ola::NewCallback(this, &DmxGateway::SendData);

        // Returning false from the callback will cause it to be cancelled.
        // ola::TimeInterval(1000000)
        select_server_->RegisterRepeatingTimeout(33, ola::NewCallback(this, &DmxGateway::SendData)); // create a constant for that! // Use the version that takes a TimeInterval instead.

        OLA_INFO << "DmxGateway was succesfully created";

        select_server_->Run();
    }



protected:

private:
    bool SendData() {
        for (unsigned int curr_univ = 0; curr_univ < universe_amount_; ++curr_univ) {
            ola_client_->SendDMX(curr_univ, dmx_data_[curr_univ], ola::client::SendDMXArgs());
        }
        return true;
    }

    ola::client::OlaClientWrapper wrapper_;
    std::vector <ola::DmxBuffer> dmx_data_;

    ola::io::SelectServer* select_server_;
    ola::client::OlaClient* ola_client_;

    unsigned int universe_amount_; // нужно ли здесь хранить количество вселенных?
};

#endif // DMXGATEWAY_H
