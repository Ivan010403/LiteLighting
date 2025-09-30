/****************************************************************************
** Meta object code from reading C++ file 'controlpanel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../include/qt_headers/control_panel/controlpanel.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlpanel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ControlPanel_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[9];
    char stringdata5[10];
    char stringdata6[9];
    char stringdata7[10];
    char stringdata8[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ControlPanel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ControlPanel_t qt_meta_stringdata_ControlPanel = {
    {
        QT_MOC_LITERAL(0, 12),  // "ControlPanel"
        QT_MOC_LITERAL(13, 10),  // "showDimmer"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "showPosition"
        QT_MOC_LITERAL(38, 8),  // "showGobo"
        QT_MOC_LITERAL(47, 9),  // "showColor"
        QT_MOC_LITERAL(57, 8),  // "showBeam"
        QT_MOC_LITERAL(66, 9),  // "showFocus"
        QT_MOC_LITERAL(76, 11)   // "showControl"
    },
    "ControlPanel",
    "showDimmer",
    "",
    "showPosition",
    "showGobo",
    "showColor",
    "showBeam",
    "showFocus",
    "showControl"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ControlPanel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ControlPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ControlPanel.offsetsAndSizes,
    qt_meta_data_ControlPanel,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ControlPanel_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ControlPanel, std::true_type>,
        // method 'showDimmer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showGobo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showBeam'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showControl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControlPanel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showDimmer(); break;
        case 1: _t->showPosition(); break;
        case 2: _t->showGobo(); break;
        case 3: _t->showColor(); break;
        case 4: _t->showBeam(); break;
        case 5: _t->showFocus(); break;
        case 6: _t->showControl(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
