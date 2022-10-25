/****************************************************************************
** Meta object code from reading C++ file 'doorsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/doorsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doorsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoorSystem_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoorSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoorSystem_t qt_meta_stringdata_DoorSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DoorSystem"
QT_MOC_LITERAL(1, 11, 9), // "SendClose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 19), // "on_BackMain_clicked"
QT_MOC_LITERAL(4, 42, 19), // "on_OpenDoor_clicked"
QT_MOC_LITERAL(5, 62, 20), // "on_CloseDoor_clicked"
QT_MOC_LITERAL(6, 83, 11), // "ButtonStyle"
QT_MOC_LITERAL(7, 95, 12), // "QPushButton*"
QT_MOC_LITERAL(8, 108, 4), // "Name"
QT_MOC_LITERAL(9, 113, 6), // "Offset"
QT_MOC_LITERAL(10, 120, 10) // "BlurRadius"

    },
    "DoorSystem\0SendClose\0\0on_BackMain_clicked\0"
    "on_OpenDoor_clicked\0on_CloseDoor_clicked\0"
    "ButtonStyle\0QPushButton*\0Name\0Offset\0"
    "BlurRadius"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoorSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    3,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    8,    9,   10,

       0        // eod
};

void DoorSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoorSystem *_t = static_cast<DoorSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendClose(); break;
        case 1: _t->on_BackMain_clicked(); break;
        case 2: _t->on_OpenDoor_clicked(); break;
        case 3: _t->on_CloseDoor_clicked(); break;
        case 4: _t->ButtonStyle((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DoorSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoorSystem::SendClose)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DoorSystem::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DoorSystem.data,
      qt_meta_data_DoorSystem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DoorSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoorSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoorSystem.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DoorSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DoorSystem::SendClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
