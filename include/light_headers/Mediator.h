#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>

#include "Fixture.h"

class Mediator : public QObject {
    Q_OBJECT
public:
    static Mediator& instance() { static Mediator m; return m; }

signals:
    void SelectingFixture();
    void UnselectingFixture();

    void SelectingCommand();
    void UnselectingCommand();

    void DeletingFixture(Fixture*);
    void CreationGroup(int, Fixture*);

private:
    Mediator() = default;
};


#endif // MEDIATOR_H
