#ifndef FIXTUREPROPERTIES_H
#define FIXTUREPROPERTIES_H
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


class FixtureProperties : public QFrame {
Q_OBJECT

public:
    explicit FixtureProperties(QWidget* parent = nullptr) : QFrame(parent) {}
    ~FixtureProperties() {}

public slots:
    void FixtureChoosen() {
        qDebug() << " ПОЛУЧИЛОСЬ! ";
    }
};

#endif // FIXTUREPROPERTIES_H
