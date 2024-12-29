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


int main(int argc, char *argv[]) {
    FixtureArray arr;
    arr.createNewFixture(0, 20, 10, "hello world");

    std::cout << arr.size() << std::endl;

    std::vector<std::vector<bool>> universe_patching_ (3, std::vector<bool>(512, true));
    Patcher x(1, arr, universe_patching_);
    std::cout << "hello world\n";

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
