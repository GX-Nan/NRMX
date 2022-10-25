/****************************************************************************
** Meta object code from reading C++ file 'windowsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form/windowsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowSystem_t {
    QByteArrayData data[19];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowSystem_t qt_meta_stringdata_WindowSystem = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WindowSystem"
QT_MOC_LITERAL(1, 13, 9), // "SendClose"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "RadioBroadcast"
QT_MOC_LITERAL(4, 39, 13), // "OutsideStatus"
QT_MOC_LITERAL(5, 53, 19), // "on_BackMain_clicked"
QT_MOC_LITERAL(6, 73, 11), // "ButtonStyle"
QT_MOC_LITERAL(7, 85, 12), // "QPushButton*"
QT_MOC_LITERAL(8, 98, 4), // "Name"
QT_MOC_LITERAL(9, 103, 6), // "Offset"
QT_MOC_LITERAL(10, 110, 10), // "BlurRadius"
QT_MOC_LITERAL(11, 121, 22), // "on_WindowClose_clicked"
QT_MOC_LITERAL(12, 144, 21), // "on_WindowOpen_clicked"
QT_MOC_LITERAL(13, 166, 21), // "on_WindowStop_clicked"
QT_MOC_LITERAL(14, 188, 18), // "ButtonStyle_Button"
QT_MOC_LITERAL(15, 207, 9), // "ShowSubUi"
QT_MOC_LITERAL(16, 217, 17), // "AirQuality_Status"
QT_MOC_LITERAL(17, 235, 13), // "Window_Status"
QT_MOC_LITERAL(18, 249, 14) // "SetInstruction"

    },
    "WindowSystem\0SendClose\0\0RadioBroadcast\0"
    "OutsideStatus\0on_BackMain_clicked\0"
    "ButtonStyle\0QPushButton*\0Name\0Offset\0"
    "BlurRadius\0on_WindowClose_clicked\0"
    "on_WindowOpen_clicked\0on_WindowStop_clicked\0"
    "ButtonStyle_Button\0ShowSubUi\0"
    "AirQuality_Status\0Window_Status\0"
    "SetInstruction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       4,    3,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   90,    2, 0x08 /* Private */,
       6,    3,   91,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    3,  101,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x0a /* Public */,
      16,    3,  109,    2, 0x0a /* Public */,
      17,    3,  116,    2, 0x0a /* Public */,
      18,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WindowSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendClose(); break;
        case 1: _t->RadioBroadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->OutsideStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->on_BackMain_clicked(); break;
        case 4: _t->ButtonStyle((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->on_WindowClose_clicked(); break;
        case 6: _t->on_WindowOpen_clicked(); break;
        case 7: _t->on_WindowStop_clicked(); break;
        case 8: _t->ButtonStyle_Button((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->ShowSubUi(); break;
        case 10: _t->AirQuality_Status((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->Window_Status((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->SetInstruction((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindowSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindowSystem::SendClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WindowSystem::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindowSystem::RadioBroadcast)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WindowSystem::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindowSystem::OutsideStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindowSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_WindowSystem.data,
    qt_meta_data_WindowSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowSystem.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WindowSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void WindowSystem::SendClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WindowSystem::RadioBroadcast(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WindowSystem::OutsideStatus(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
