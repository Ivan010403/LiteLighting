#include <stdlib.h>
#include <iostream>
#include <uuid/uuid.h>
//#include <curses.h> // problems with macro scroll

#include <QApplication>
#include "qt_headers/mainwindow.h"


#include "light_headers/Patcher.h"

int main(int argc, char *argv[]) {
    ola::InitLogging(ola::OLA_LOG_INFO, ola::OLA_LOG_STDERR);

    DmxGateway gtw(1);

    std::cout <<"Hello world" << std::endl;
    if (!gtw.Start()) {
        OLA_FATAL << "Failed to start OLA thread";
        exit(1);
    }

    // When it's time to exit, Stop the OLA thread.
    gtw.Stop();
    gtw.Join();
}
    // DmxGateway test(4);

    // FixtureArray arr;
    // std::cout << arr.size() << std::endl;

    // std::vector<std::vector<bool>> universe_patch (3, std::vector<bool>(512, true));
    // Patcher x(1, arr, universe_patch);

    // std::unordered_map<ChannelType, unsigned char> test {{ChannelType::Dimmer,20}, {ChannelType::G,21}, {ChannelType::B,22}, {ChannelType::R,23}};

    // x.PatchNewFixture(0, 20, 4, "led_wash", test);

  // QApplication a(argc, argv);
  // MainWindow w;
  // w.show();

  // unsigned int universe = 0;  // universe to use for sending data
  // // turn on OLA logging
  // ola::InitLogging(ola::OLA_LOG_WARN, ola::OLA_LOG_STDERR);
  // ola::DmxBuffer buffer;  // A DmxBuffer to hold the data.
  // buffer.Blackout();  // Set all channels to 0
  // // Create a new client.
  // ola::client::StreamingClient ola_client(
  //     (ola::client::StreamingClient::Options()));
  // // Setup the client, this connects to the server
  // if (!ola_client.Setup()) {
  //   std::cerr << "Setup failed" << std::endl;
  //   exit(1);
  // }

  // // Send 100 frames to the server. Increment slot (channel) 0 each time a
  // // frame is sent.

  // buffer.SetChannel(341, 100);

  // buffer.SetChannel(349, 255);
  // buffer.SetChannel(350, 255);
  // buffer.SetChannel(351, 0);
  // ola_client.SendDmx(universe, buffer);

  // for (unsigned int i = 0; i < 255; i++) {

  //   buffer.SetChannel(352, i);
  //   buffer.SetChannel(350, 255 - i);

  //   if (!ola_client.SendDmx(universe, buffer)) {
  //     std::cout << "Send DMX failed" << std::endl;
  //     exit(1);
  //   }
  //   usleep(70000);
  //   //usleep(25000);   // sleep for 25ms between frames.
  // }

  // return a.exec();
