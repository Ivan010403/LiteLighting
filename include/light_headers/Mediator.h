#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>

class Mediator : public QObject {
    Q_OBJECT
public:
    static Mediator& instance() { static Mediator m; return m; }

signals:
    void SelectingFixture();
    void UnselectingFixture();

    void SelectingCommand();
    void UnselectingCommand();

private:
    Mediator() = default;
};


#endif // MEDIATOR_H
