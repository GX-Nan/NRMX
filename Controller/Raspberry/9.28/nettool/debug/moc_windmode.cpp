/****************************************************************************
** Meta object code from reading C++ file 'windmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form/windmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindMode_t {
    QByteArrayData data[10];
    char stringdata0[137];
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
QT_MOC_LITERAL(3, 25, 5), // "Clear"
QT_MOC_LITERAL(4, 31, 6), // "Enable"
QT_MOC_LITERAL(5, 38, 4), // "Falg"
QT_MOC_LITERAL(6, 43, 18), // "on_SeaMode_clicked"
QT_MOC_LITERAL(7, 62, 23), // "on_SurroundMode_clicked"
QT_MOC_LITERAL(8, 86, 22), // "on_NaturalMode_clicked"
QT_MOC_LITERAL(9, 109, 27) // "on_StereoscopicMode_clicked"

    },
    "WindMode\0RadioBroadcast\0\0Clear\0Enable\0"
    "Falg\0on_SeaMode_clicked\0on_SurroundMode_clicked\0"
    "on_NaturalMode_clicked\0"
    "on_StereoscopicMode_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindMode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   52,    2, 0x0a /* Public */,
       4,    1,   53,    2, 0x0a /* Public */,
       6,    0,   56,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WindMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RadioBroadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Clear(); break;
        case 2: _t->Enable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_SeaMode_clicked(); break;
        case 4: _t->on_SurroundMode_clicked(); break;
        case 5: _t->on_NaturalMode_clicked(); break;
        case 6: _t->on_StereoscopicMode_clicked(); break;
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
    }
}

QT_INIT_METAOBJECT const QMetaObject WindMode::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_WindMode.data,
    qt_meta_data_WindMode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WindMode::RadioBroadcast(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
