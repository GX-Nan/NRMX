/****************************************************************************
** Meta object code from reading C++ file 'windmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/windmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindMode_t {
    QByteArrayData data[15];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindMode_t qt_meta_stringdata_WindMode = {
    {
QT_MOC_LITERAL(0, 0, 8), // "WindMode"
QT_MOC_LITERAL(1, 9, 14), // "RadioBroadcast"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "SendToWx"
QT_MOC_LITERAL(4, 34, 5), // "Clear"
QT_MOC_LITERAL(5, 40, 6), // "Enable"
QT_MOC_LITERAL(6, 47, 4), // "Falg"
QT_MOC_LITERAL(7, 52, 18), // "on_SeaMode_clicked"
QT_MOC_LITERAL(8, 71, 23), // "on_SurroundMode_clicked"
QT_MOC_LITERAL(9, 95, 22), // "on_NaturalMode_clicked"
QT_MOC_LITERAL(10, 118, 27), // "on_StereoscopicMode_clicked"
QT_MOC_LITERAL(11, 146, 15), // "ButtonStylePlan"
QT_MOC_LITERAL(12, 162, 14), // "BackgroundPlan"
QT_MOC_LITERAL(13, 177, 8), // "ModeCtrl"
QT_MOC_LITERAL(14, 186, 20) // "on_CloseMode_clicked"

    },
    "WindMode\0RadioBroadcast\0\0SendToWx\0"
    "Clear\0Enable\0Falg\0on_SeaMode_clicked\0"
    "on_SurroundMode_clicked\0on_NaturalMode_clicked\0"
    "on_StereoscopicMode_clicked\0ButtonStylePlan\0"
    "BackgroundPlan\0ModeCtrl\0on_CloseMode_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    2,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       7,    0,   86,    2, 0x0a /* Public */,
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    5,   90,    2, 0x0a /* Public */,
      12,    5,  101,    2, 0x0a /* Public */,
      13,    1,  112,    2, 0x0a /* Public */,
      14,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void WindMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WindMode *_t = static_cast<WindMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RadioBroadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendToWx((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->Clear(); break;
        case 3: _t->Enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_SeaMode_clicked(); break;
        case 5: _t->on_SurroundMode_clicked(); break;
        case 6: _t->on_NaturalMode_clicked(); break;
        case 7: _t->on_StereoscopicMode_clicked(); break;
        case 8: _t->ButtonStylePlan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 9: _t->BackgroundPlan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 10: _t->ModeCtrl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_CloseMode_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WindMode::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindMode::RadioBroadcast)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WindMode::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WindMode::SendToWx)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindMode::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WindMode.data,
      qt_meta_data_WindMode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WindMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindMode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindMode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WindMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void WindMode::RadioBroadcast(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WindMode::SendToWx(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
