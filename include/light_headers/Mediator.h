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
    void SelectingCommand();

    void DeletingFixture(Fixture*);
    void CreationGroup(int, Fixture*, const QString&);

    void SaveBuskToShow();
    void LoadBuskFromShow();

private:
    Mediator() = default;
};


#endif // MEDIATOR_H
