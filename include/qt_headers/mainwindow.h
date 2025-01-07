#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };

class Counter : public QObject {
    Q_OBJECT

private:
    int nValue;

public:

    Counter() : QObject(), nValue(0) {}

public slots:
    void slotInc() {
        emit counterChanged(++nValue);

        if (nValue == 5) {
            emit goodbye();
        }
    }

signals:
    void goodbye();
    void counterChanged(int);
};

#endif // MAINWINDOW_H
