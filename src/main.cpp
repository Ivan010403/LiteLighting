#include <uuid/uuid.h>
//#include <curses.h> // problems with macro scroll

#include <QtWidgets>
#include <QApplication>
#include "qt_headers/mainwindow.h"
#include "styles/main/main_palette.h"

#include "light_headers/DmxGateway.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setStyle(QStyleFactory::create("Fusion"));

    app.setPalette(СreateAppPalette());

    const unsigned int univ_amount = 10; // сделать нормальный ввод количество юниверсов
    DmxGateway dmx_gtw(univ_amount);
    if (!dmx_gtw.Start()) {
        qFatal("Failed to start OLA thread");
    }

    MainWindow mw(dmx_gtw);

    return app.exec();
}



