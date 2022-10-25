/****************************************************************************
** Meta object code from reading C++ file 'analysis_cutarin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Information/analysis_cutarin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysis_cutarin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Analysis_Cutarin_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analysis_Cutarin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analysis_Cutarin_t qt_meta_stringdata_Analysis_Cutarin = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Analysis_Cutarin"
QT_MOC_LITERAL(1, 17, 13), // "StatusSignals"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "BrightnessSignals"
QT_MOC_LITERAL(4, 50, 12), // "Receive_Data"
QT_MOC_LITERAL(5, 63, 22), // "QMultiMap<int,QString>"
QT_MOC_LITERAL(6, 86, 4), // "Data"
QT_MOC_LITERAL(7, 91, 11), // "Handle_Data"
QT_MOC_LITERAL(8, 103, 15) // "Handle_Data_Esp"

    },
    "Analysis_Cutarin\0StatusSignals\0\0"
    "BrightnessSignals\0Receive_Data\0"
    "QMultiMap<int,QString>\0Data\0Handle_Data\0"
    "Handle_Data_Esp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analysis_Cutarin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       3,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void Analysis_Cutarin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Analysis_Cutarin *_t = static_cast<Analysis_Cutarin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StatusSignals((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->BrightnessSignals((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Receive_Data((*reinterpret_cast< QMultiMap<int,QString>(*)>(_a[1]))); break;
        case 3: _t->Handle_Data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Handle_Data_Esp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Analysis_Cutarin::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Cutarin::StatusSignals)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Analysis_Cutarin::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Analysis_Cutarin::BrightnessSignals)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Analysis_Cutarin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Analysis_Cutarin.data,
      qt_meta_data_Analysis_Cutarin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Analysis_Cutarin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analysis_Cutarin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Analysis_Cutarin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Analysis_Cutarin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Analysis_Cutarin::StatusSignals(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Analysis_Cutarin::BrightnessSignals(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
