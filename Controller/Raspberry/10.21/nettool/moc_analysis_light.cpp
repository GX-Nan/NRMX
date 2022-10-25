/****************************************************************************
** Meta object code from reading C++ file 'analysis_light.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Information/analysis_light.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysis_light.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Analysis_Light_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analysis_Light_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analysis_Light_t qt_meta_stringdata_Analysis_Light = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Analysis_Light"
QT_MOC_LITERAL(1, 15, 13), // "StatusSignals"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "Function"
QT_MOC_LITERAL(4, 39, 3), // "Sub"
QT_MOC_LITERAL(5, 43, 5), // "Value"
QT_MOC_LITERAL(6, 49, 12), // "Receive_Data"
QT_MOC_LITERAL(7, 62, 22), // "QMultiMap<int,QString>"
QT_MOC_LITERAL(8, 85, 4), // "Data"
QT_MOC_LITERAL(9, 90, 11) // "Handle_Data"

    },
    "Analysis_Light\0StatusSignals\0\0Function\0"
    "Sub\0Value\0Receive_Data\0QMultiMap<int,QString>\0"
    "Data\0Handle_Data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analysis_Light[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   36,    2, 0x0a /* Public */,
       9,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void Analysis_Light::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Analysis_Light *_t = static_cast<Analysis_Light *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StatusSignals((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->Receive_Data((*reinterpret_cast< QMultiMap<int,QString>(*)>(_a[1]))); break;
        case 2: _t->Handle_Data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Analysis_Light::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Light::StatusSignals)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Analysis_Light::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Analysis_Light.data,
      qt_meta_data_Analysis_Light,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Analysis_Light::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analysis_Light::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Analysis_Light.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Analysis_Light::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Analysis_Light::StatusSignals(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
