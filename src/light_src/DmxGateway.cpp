#include "light_headers/DmxGateway.h"

bool DmxGateway::Start() {
    if (!wrapper_.Setup()) {
        OLA_FATAL << "DmxGateway::Start() failed";
        return false;
    }

    GatewaySetup();

    return ola::thread::Thread::Start();
}

void DmxGateway::Stop() {
    OLA_INFO << "DmxGateway::Stop() stop the select_server";
    select_server_->Terminate();
}

ola::DmxBuffer& DmxGateway::GetBuffer(unsigned int universe_id) {
    return dmx_data_[universe_id];
}

void* DmxGateway::Run() {
    OLA_INFO << "DmxGateway::Run() run the thread";
    select_server_->Run();
    return NULL;
}

void DmxGateway::GatewaySetup() {
    ola_client_ = wrapper_.GetClient(); // getclient константный метод, а я присваиваю неконстантному указателю
    select_server_ = wrapper_.GetSelectServer();

    select_server_->RegisterRepeatingTimeout(ola_30_fps_, ola::NewCallback(this, &DmxGateway::SendData));

    ola_client_->SetCloseHandler(ola::NewSingleCallback(this, &DmxGateway::ConnectionClosed));
    OLA_INFO << "DmxGateway::GatewaySetup() was succesfully created with callback 30 fps";
}

void DmxGateway::ConnectionClosed() {
    OLA_FATAL << "Connection to olad was closed";
    select_server_->Terminate();
}

// Returning false from the callback will cause it to be cancelled.
bool DmxGateway::SendData() {
    // OLA_FATAL << static_cast<int>(dmx_data_[0].Get(0));
    for (unsigned int curr_univ = 0; curr_univ < universe_amount_; ++curr_univ) {
        ola_client_->SendDMX(curr_univ, dmx_data_[curr_univ], casual_dmx_args_);
    }
    return true;
}
