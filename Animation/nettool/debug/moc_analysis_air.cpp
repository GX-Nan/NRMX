/****************************************************************************
** Meta object code from reading C++ file 'analysis_air.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Information/analysis_air.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysis_air.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Analysis_Air_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analysis_Air_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analysis_Air_t qt_meta_stringdata_Analysis_Air = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Analysis_Air"
QT_MOC_LITERAL(1, 13, 11), // "Air_UiValue"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "Data"
QT_MOC_LITERAL(4, 31, 12), // "Receive_Data"
QT_MOC_LITERAL(5, 44, 22), // "QMultiMap<int,QString>"
QT_MOC_LITERAL(6, 67, 11), // "Handle_Data"
QT_MOC_LITERAL(7, 79, 11), // "Data_Update"
QT_MOC_LITERAL(8, 91, 7) // "Lastest"

    },
    "Analysis_Air\0Air_UiValue\0\0Data\0"
    "Receive_Data\0QMultiMap<int,QString>\0"
    "Handle_Data\0Data_Update\0Lastest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analysis_Air[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 3,    8,

       0        // eod
};

void Analysis_Air::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Analysis_Air *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Air_UiValue((*reinterpret_cast< const Data(*)>(_a[1]))); break;
        case 1: _t->Receive_Data((*reinterpret_cast< QMultiMap<int,QString>(*)>(_a[1]))); break;
        case 2: _t->Handle_Data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Data_Update((*reinterpret_cast< Data(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Data >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Data >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Analysis_Air::*)(const Data );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Air::Air_UiValue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Analysis_Air::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Analysis_Air.data,
    qt_meta_data_Analysis_Air,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Analysis_Air::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analysis_Air::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Analysis_Air.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Analysis_Air::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Analysis_Air::Air_UiValue(const Data _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
