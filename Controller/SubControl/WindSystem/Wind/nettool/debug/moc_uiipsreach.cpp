/****************************************************************************
** Meta object code from reading C++ file 'uiipsreach.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form/uiipsreach.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiipsreach.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UiIPSreach_t {
    QByteArrayData data[16];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiIPSreach_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiIPSreach_t qt_meta_stringdata_UiIPSreach = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UiIPSreach"
QT_MOC_LITERAL(1, 11, 13), // "clientConnect"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "TxtMainClear"
QT_MOC_LITERAL(4, 39, 12), // "TxtMainColor"
QT_MOC_LITERAL(5, 52, 16), // "ClientDisconnect"
QT_MOC_LITERAL(6, 69, 13), // "ClientConnect"
QT_MOC_LITERAL(7, 83, 10), // "ClientSend"
QT_MOC_LITERAL(8, 94, 8), // "SreachIP"
QT_MOC_LITERAL(9, 103, 10), // "ClientRecv"
QT_MOC_LITERAL(10, 114, 17), // "on_FindIP_clicked"
QT_MOC_LITERAL(11, 132, 21), // "on_ClientSend_clicked"
QT_MOC_LITERAL(12, 154, 20), // "on_ToConnect_clicked"
QT_MOC_LITERAL(13, 175, 21), // "on_Disconnect_clicked"
QT_MOC_LITERAL(14, 197, 14), // "lineeditEnable"
QT_MOC_LITERAL(15, 212, 21) // "on_pushButton_clicked"

    },
    "UiIPSreach\0clientConnect\0\0TxtMainClear\0"
    "TxtMainColor\0ClientDisconnect\0"
    "ClientConnect\0ClientSend\0SreachIP\0"
    "ClientRecv\0on_FindIP_clicked\0"
    "on_ClientSend_clicked\0on_ToConnect_clicked\0"
    "on_Disconnect_clicked\0lineeditEnable\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiIPSreach[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,
       6,    0,   90,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,
       8,    1,   94,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UiIPSreach::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UiIPSreach *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientConnect(); break;
        case 1: _t->TxtMainClear(); break;
        case 2: _t->TxtMainColor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->ClientDisconnect(); break;
        case 4: _t->ClientConnect(); break;
        case 5: _t->ClientSend((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->SreachIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->ClientRecv((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_FindIP_clicked(); break;
        case 9: _t->on_ClientSend_clicked(); break;
        case 10: _t->on_ToConnect_clicked(); break;
        case 11: _t->on_Disconnect_clicked(); break;
        case 12: _t->lineeditEnable(); break;
        case 13: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UiIPSreach::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::clientConnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::TxtMainClear)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::TxtMainColor)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::ClientDisconnect)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::ClientConnect)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::ClientSend)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::SreachIP)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (UiIPSreach::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UiIPSreach::ClientRecv)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UiIPSreach::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_UiIPSreach.data,
    qt_meta_data_UiIPSreach,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UiIPSreach::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiIPSreach::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UiIPSreach.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int UiIPSreach::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void UiIPSreach::clientConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UiIPSreach::TxtMainClear()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UiIPSreach::TxtMainColor(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UiIPSreach::ClientDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void UiIPSreach::ClientConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void UiIPSreach::ClientSend(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void UiIPSreach::SreachIP(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void UiIPSreach::ClientRecv(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
