#include <stdlib.h>
#include <iostream>
#include <uuid/uuid.h>
//#include <curses.h> // problems with macro scroll

#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include "qt_headers/mainwindow.h"

#include "light_headers/Patcher.h"

#include "styles/main_style.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // stylization of qt application
    app.setPalette(СreateAppPalette());

    MainWindow mw;
    mw.showMaximized();



    return app.exec();
}



