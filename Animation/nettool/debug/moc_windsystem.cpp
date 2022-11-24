/****************************************************************************
** Meta object code from reading C++ file 'windsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form/windsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindSystem_t {
    QByteArrayData data[24];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindSystem_t qt_meta_stringdata_WindSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WindSystem"
QT_MOC_LITERAL(1, 11, 9), // "SendClose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "Clear"
QT_MOC_LITERAL(4, 28, 6), // "Enable"
QT_MOC_LITERAL(5, 35, 4), // "Falg"
QT_MOC_LITERAL(6, 40, 14), // "RadioBroadcast"
QT_MOC_LITERAL(7, 55, 12), // "Class_Update"
QT_MOC_LITERAL(8, 68, 9), // "Wind_Data"
QT_MOC_LITERAL(9, 78, 4), // "data"
QT_MOC_LITERAL(10, 83, 16), // "Xprogress_Update"
QT_MOC_LITERAL(11, 100, 10), // "AirQuality"
QT_MOC_LITERAL(12, 111, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(13, 135, 11), // "ButtonStyle"
QT_MOC_LITERAL(14, 147, 12), // "QPushButton*"
QT_MOC_LITERAL(15, 160, 4), // "Name"
QT_MOC_LITERAL(16, 165, 6), // "Offset"
QT_MOC_LITERAL(17, 172, 10), // "BlurRadius"
QT_MOC_LITERAL(18, 183, 19), // "on_StopMode_clicked"
QT_MOC_LITERAL(19, 203, 18), // "on_MinMode_clicked"
QT_MOC_LITERAL(20, 222, 18), // "on_MidMode_clicked"
QT_MOC_LITERAL(21, 241, 19), // "on_HighMode_clicked"
QT_MOC_LITERAL(22, 261, 11), // "ReceiveData"
QT_MOC_LITERAL(23, 273, 8) // "VarValue"

    },
    "WindSystem\0SendClose\0\0Clear\0Enable\0"
    "Falg\0RadioBroadcast\0Class_Update\0"
    "Wind_Data\0data\0Xprogress_Update\0"
    "AirQuality\0on_pushButton_2_clicked\0"
    "ButtonStyle\0QPushButton*\0Name\0Offset\0"
    "BlurRadius\0on_StopMode_clicked\0"
    "on_MinMode_clicked\0on_MidMode_clicked\0"
    "on_HighMode_clicked\0ReceiveData\0"
    "VarValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,
       7,    1,   87,    2, 0x06 /* Public */,
      10,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   93,    2, 0x08 /* Private */,
      13,    3,   94,    2, 0x08 /* Private */,
      18,    0,  101,    2, 0x08 /* Private */,
      19,    0,  102,    2, 0x08 /* Private */,
      20,    0,  103,    2, 0x08 /* Private */,
      21,    0,  104,    2, 0x08 /* Private */,
      22,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   23,

       0        // eod
};

void WindSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendClose(); break;
        case 1: _t->Clear(); break;
        case 2: _t->Enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->RadioBroadcast((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->Class_Update((*reinterpret_cast< const Wind_Data(*)>(_a[1]))); break;
        case 5: _t->Xprogress_Update((*reinterpret_cast< const AirQuality(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->ButtonStyle((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->on_StopMode_clicked(); break;
        case 9: _t->on_MinMode_clicked(); break;
        case 10: _t->on_MidMode_clicked(); break;
        case 11: _t->on_HighMode_clicked(); break;
        case 12: _t->ReceiveData((*reinterpret_cast< const Wind_Data(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindSystem::SendClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WindSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindSystem::Clear)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WindSystem::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindSystem::Enable)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WindSystem::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindSystem::RadioBroadcast)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WindSystem::*)(const Wind_Data );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindSystem::Class_Update)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WindSystem::*)(const AirQuality );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindSystem::Xprogress_Update)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_WindSystem.data,
    qt_meta_data_WindSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindSystem.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WindSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WindSystem::SendClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WindSystem::Clear()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WindSystem::Enable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WindSystem::RadioBroadcast(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WindSystem::Class_Update(const Wind_Data _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WindSystem::Xprogress_Update(const AirQuality _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
