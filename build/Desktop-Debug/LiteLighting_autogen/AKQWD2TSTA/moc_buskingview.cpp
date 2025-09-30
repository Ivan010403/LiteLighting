/****************************************************************************
** Meta object code from reading C++ file 'buskingview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../include/qt_headers/middle_panel/busking/busking_view/buskingview.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buskingview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_BuskingView_t {
    uint offsetsAndSizes[28];
    char stringdata0[12];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[18];
    char stringdata5[7];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[16];
    char stringdata9[15];
    char stringdata10[14];
    char stringdata11[18];
    char stringdata12[11];
    char stringdata13[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_BuskingView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_BuskingView_t qt_meta_stringdata_BuskingView = {
    {
        QT_MOC_LITERAL(0, 11),  // "BuskingView"
        QT_MOC_LITERAL(12, 16),  // "SelectingByGroup"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 8),  // "group_id"
        QT_MOC_LITERAL(39, 17),  // "PressingByFixture"
        QT_MOC_LITERAL(57, 6),  // "fix_id"
        QT_MOC_LITERAL(64, 15),  // "onBtnAddClicked"
        QT_MOC_LITERAL(80, 14),  // "onBtnAddSocket"
        QT_MOC_LITERAL(95, 15),  // "onSocketPatched"
        QT_MOC_LITERAL(111, 14),  // "FixtureButton*"
        QT_MOC_LITERAL(126, 13),  // "SocketButton*"
        QT_MOC_LITERAL(140, 17),  // "onSocketUnpatched"
        QT_MOC_LITERAL(158, 10),  // "SaveToShow"
        QT_MOC_LITERAL(169, 12)   // "LoadFromShow"
    },
    "BuskingView",
    "SelectingByGroup",
    "",
    "group_id",
    "PressingByFixture",
    "fix_id",
    "onBtnAddClicked",
    "onBtnAddSocket",
    "onSocketPatched",
    "FixtureButton*",
    "SocketButton*",
    "onSocketUnpatched",
    "SaveToShow",
    "LoadFromShow"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_BuskingView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   68,    2, 0x0a,    5 /* Public */,
       7,    0,   69,    2, 0x0a,    6 /* Public */,
       8,    3,   70,    2, 0x0a,    7 /* Public */,
      11,    3,   77,    2, 0x0a,   11 /* Public */,
      12,    0,   84,    2, 0x0a,   15 /* Public */,
      13,    0,   85,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 10, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 10, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BuskingView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BuskingView.offsetsAndSizes,
    qt_meta_data_BuskingView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_BuskingView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BuskingView, std::true_type>,
        // method 'SelectingByGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'PressingByFixture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onBtnAddClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onBtnAddSocket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSocketPatched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FixtureButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SocketButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSocketUnpatched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FixtureButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<SocketButton *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SaveToShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LoadFromShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BuskingView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BuskingView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SelectingByGroup((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->PressingByFixture((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->onBtnAddClicked(); break;
        case 3: _t->onBtnAddSocket(); break;
        case 4: _t->onSocketPatched((*reinterpret_cast< std::add_pointer_t<FixtureButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SocketButton*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->onSocketUnpatched((*reinterpret_cast< std::add_pointer_t<FixtureButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SocketButton*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->SaveToShow(); break;
        case 7: _t->LoadFromShow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FixtureButton* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SocketButton* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FixtureButton* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SocketButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BuskingView::*)(int );
            if (_t _q_method = &BuskingView::SelectingByGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BuskingView::*)(int );
            if (_t _q_method = &BuskingView::PressingByFixture; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *BuskingView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BuskingView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BuskingView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BuskingView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BuskingView::SelectingByGroup(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BuskingView::PressingByFixture(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
