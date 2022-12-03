/****************************************************************************
** Meta object code from reading C++ file 'analysis_wind.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Information/analysis_wind.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysis_wind.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Analysis_Wind_t {
    QByteArrayData data[19];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analysis_Wind_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analysis_Wind_t qt_meta_stringdata_Analysis_Wind = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Analysis_Wind"
QT_MOC_LITERAL(1, 14, 11), // "Wind_UiData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "Wind_Data"
QT_MOC_LITERAL(4, 37, 4), // "Data"
QT_MOC_LITERAL(5, 42, 15), // "AirQuality_Data"
QT_MOC_LITERAL(6, 58, 10), // "AirQuality"
QT_MOC_LITERAL(7, 69, 14), // "IndoorAirJudge"
QT_MOC_LITERAL(8, 84, 9), // "SendToAir"
QT_MOC_LITERAL(9, 94, 11), // "SendToLight"
QT_MOC_LITERAL(10, 106, 14), // "SendToLocation"
QT_MOC_LITERAL(11, 121, 12), // "Receive_Data"
QT_MOC_LITERAL(12, 134, 22), // "QMultiMap<int,QString>"
QT_MOC_LITERAL(13, 157, 16), // "Handle_Data_Wind"
QT_MOC_LITERAL(14, 174, 22), // "Handle_Data_AirQuality"
QT_MOC_LITERAL(15, 197, 11), // "Data_Update"
QT_MOC_LITERAL(16, 209, 7), // "Lastest"
QT_MOC_LITERAL(17, 217, 11), // "Wind_Decode"
QT_MOC_LITERAL(18, 229, 5) // "Value"

    },
    "Analysis_Wind\0Wind_UiData\0\0Wind_Data\0"
    "Data\0AirQuality_Data\0AirQuality\0"
    "IndoorAirJudge\0SendToAir\0SendToLight\0"
    "SendToLocation\0Receive_Data\0"
    "QMultiMap<int,QString>\0Handle_Data_Wind\0"
    "Handle_Data_AirQuality\0Data_Update\0"
    "Lastest\0Wind_Decode\0Value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analysis_Wind[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,
       8,    2,   80,    2, 0x06 /* Public */,
       9,    1,   85,    2, 0x06 /* Public */,
      10,    2,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    2,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void Analysis_Wind::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Analysis_Wind *_t = static_cast<Analysis_Wind *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Wind_UiData((*reinterpret_cast< const Wind_Data(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->AirQuality_Data((*reinterpret_cast< const AirQuality(*)>(_a[1]))); break;
        case 2: _t->IndoorAirJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SendToAir((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->SendToLight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SendToLocation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->Receive_Data((*reinterpret_cast< QMultiMap<int,QString>(*)>(_a[1]))); break;
        case 7: _t->Handle_Data_Wind((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->Handle_Data_AirQuality((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->Data_Update((*reinterpret_cast< Wind_Data(*)>(_a[1]))); break;
        case 10: _t->Wind_Decode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Analysis_Wind::*)(const Wind_Data , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Wind::Wind_UiData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Analysis_Wind::*)(const AirQuality );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Wind::AirQuality_Data)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Analysis_Wind::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Wind::IndoorAirJudge)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Analysis_Wind::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Wind::SendToAir)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Analysis_Wind::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Wind::SendToLight)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Analysis_Wind::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Wind::SendToLocation)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Analysis_Wind::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Analysis_Wind.data,
      qt_meta_data_Analysis_Wind,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Analysis_Wind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analysis_Wind::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Analysis_Wind.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Analysis_Wind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Analysis_Wind::Wind_UiData(const Wind_Data _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Analysis_Wind::AirQuality_Data(const AirQuality _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Analysis_Wind::IndoorAirJudge(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Analysis_Wind::SendToAir(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Analysis_Wind::SendToLight(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Analysis_Wind::SendToLocation(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
