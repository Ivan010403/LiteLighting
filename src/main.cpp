#include <uuid/uuid.h>
//#include <curses.h> // problems with macro scroll

#include <QtWidgets>
#include <QApplication>

#include "qt_headers/main_window/mainwindow.h"
#include "styles/main/main_palette.h"

#include "light_headers/DmxGateway.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setStyle(QStyleFactory::create("Fusion"));

    //stylization of qt application
    app.setPalette(СreateAppPalette());

    const unsigned int univ_amount = 1;
    DmxGateway dmx_gtw(univ_amount);
    if (!dmx_gtw.Start()) {
        qFatal("Failed to start OLA thread");
    }

    MainWindow mw(dmx_gtw);
    mw.showMaximized();

    return app.exec();
}



