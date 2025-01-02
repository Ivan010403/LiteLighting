#include <stdlib.h>
#include <unistd.h>
#include <ola/DmxBuffer.h>
#include <ola/Logging.h>
#include <ola/client/StreamingClient.h>
#include <iostream>
#include <uuid/uuid.h>
//#include <curses.h> // problems with macro scroll

#include <QApplication>

#include "qt_headers/mainwindow.h"
#include "light_headers/Patcher.h"
#include "light_headers/FixtureArray.h"
#include "light_headers/DmxGateway.h"
#include <time.h>
#include <chrono>

int main(int argc, char *argv[]) {
    ola::DmxBuffer test;
    test.Blackout();

    const unsigned int channels = 20;

    const int amount_fixtures = 12;
    uint8_t* fixtures[amount_fixtures];

    for (int var = 0; var < amount_fixtures; ++var) {
        fixtures[var] = new uint8_t[channels] {};

        for (int i = 0; i < channels; ++i) {
            fixtures[var][i] = (var*channels) + i;
        }
    }

    const int measure = 50000;

    //----------------------FIRST----------------------------
    auto begin = std::chrono::steady_clock::now();
    for (int val = 0; val < measure; ++val) {
        for (int i = 0; i < amount_fixtures; ++i) {
            test.SetRange(i*channels, fixtures[i], channels);
        }
    }
    auto end = std::chrono::steady_clock::now();


    const uint8_t* ptr = test.GetRaw();
    uint8_t* ptr_my = const_cast<uint8_t*>(ptr);

    // std::wcout <<"test = " << &test << " ptr pure = " << ptr << std::endl;
    // std::wcout <<"ptrMy = " << ptr_my << std::endl;

    //----------------------SECOND----------------------------
    // auto begin = std::chrono::steady_clock::now();
    // for (int val = 0; val < measure; ++val) {
    //     for (int i = 0; i < amount_fixtures; ++i) {
    //         for (int j = 0; j < channels; ++j) {
    //             ptr_my[i*channels + j] = fixtures[i][j];
    //         }
    //     }
    // }
    // auto end = std::chrono::steady_clock::now();

    // for (int i = 0; i < amount_fixtures; ++i) {
    //     for (int j = 0; j < channels; ++j) {
    //         std::wcout << ptr_my[i*channels + j] << " ";
    //     }
    //     std::wcout << std::endl;
    // }


    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "The time: " << elapsed_ms.count() << " ms\n";



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

  return 0;
  // return a.exec();
}
