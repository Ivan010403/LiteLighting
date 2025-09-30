/****************************************************************************
** Meta object code from reading C++ file 'Mediator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../include/light_headers/Mediator.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mediator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Mediator_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[16];
    char stringdata5[9];
    char stringdata6[14];
    char stringdata7[15];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Mediator_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Mediator_t qt_meta_stringdata_Mediator = {
    {
        QT_MOC_LITERAL(0, 8),  // "Mediator"
        QT_MOC_LITERAL(9, 16),  // "SelectingFixture"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 16),  // "SelectingCommand"
        QT_MOC_LITERAL(44, 15),  // "DeletingFixture"
        QT_MOC_LITERAL(60, 8),  // "Fixture*"
        QT_MOC_LITERAL(69, 13),  // "CreationGroup"
        QT_MOC_LITERAL(83, 14),  // "SaveBuskToShow"
        QT_MOC_LITERAL(98, 16)   // "LoadBuskFromShow"
    },
    "Mediator",
    "SelectingFixture",
    "",
    "SelectingCommand",
    "DeletingFixture",
    "Fixture*",
    "CreationGroup",
    "SaveBuskToShow",
    "LoadBuskFromShow"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Mediator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    1,   52,    2, 0x06,    3 /* Public */,
       6,    3,   55,    2, 0x06,    5 /* Public */,
       7,    0,   62,    2, 0x06,    9 /* Public */,
       8,    0,   63,    2, 0x06,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Mediator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Mediator.offsetsAndSizes,
    qt_meta_data_Mediator,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Mediator_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Mediator, std::true_type>,
        // method 'SelectingFixture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SelectingCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeletingFixture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Fixture *, std::false_type>,
        // method 'CreationGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<Fixture *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'SaveBuskToShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LoadBuskFromShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Mediator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mediator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SelectingFixture(); break;
        case 1: _t->SelectingCommand(); break;
        case 2: _t->DeletingFixture((*reinterpret_cast< std::add_pointer_t<Fixture*>>(_a[1]))); break;
        case 3: _t->CreationGroup((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Fixture*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 4: _t->SaveBuskToShow(); break;
        case 5: _t->LoadBuskFromShow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mediator::*)();
            if (_t _q_method = &Mediator::SelectingFixture; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Mediator::*)();
            if (_t _q_method = &Mediator::SelectingCommand; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Mediator::*)(Fixture * );
            if (_t _q_method = &Mediator::DeletingFixture; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Mediator::*)(int , Fixture * , const QString & );
            if (_t _q_method = &Mediator::CreationGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Mediator::*)();
            if (_t _q_method = &Mediator::SaveBuskToShow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Mediator::*)();
            if (_t _q_method = &Mediator::LoadBuskFromShow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *Mediator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mediator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mediator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mediator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Mediator::SelectingFixture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Mediator::SelectingCommand()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Mediator::DeletingFixture(Fixture * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Mediator::CreationGroup(int _t1, Fixture * _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Mediator::SaveBuskToShow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Mediator::LoadBuskFromShow()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
