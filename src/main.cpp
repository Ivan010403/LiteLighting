#include <stdlib.h>
#include <unistd.h>
#include <ola/DmxBuffer.h>
#include <ola/Logging.h>
#include <ola/client/StreamingClient.h>
#include <iostream>
#include <uuid/uuid.h>
//#include <curses.h> // problems with macro scroll

#include "qt_headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  unsigned int universe = 1;  // universe to use for sending data
  // turn on OLA logging
  ola::InitLogging(ola::OLA_LOG_WARN, ola::OLA_LOG_STDERR);
  ola::DmxBuffer buffer;  // A DmxBuffer to hold the data.
  buffer.Blackout();  // Set all channels to 0
  // Create a new client.
  ola::client::StreamingClient ola_client(
      (ola::client::StreamingClient::Options()));
  // Setup the client, this connects to the server
  if (!ola_client.Setup()) {
    std::cerr << "Setup failed" << std::endl;
    exit(1);
  }

  // Send 100 frames to the server. Increment slot (channel) 0 each time a
  // frame is sent.
  for (unsigned int i = 0; i < 500; i++) {
    buffer.SetChannel(0, i);
    if (!ola_client.SendDmx(universe, buffer)) {
      std::cout << "Send DMX failed" << std::endl;
      exit(1);
    }
    usleep(25000);   // sleep for 25ms between frames.
  }

  return a.exec();
}
