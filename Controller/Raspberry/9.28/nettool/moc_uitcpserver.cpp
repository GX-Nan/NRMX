/****************************************************************************
** Meta object code from reading C++ file 'uitcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/uitcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uitcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_uiTcpServer_t {
    QByteArrayData data[11];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uiTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uiTcpServer_t qt_meta_stringdata_uiTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "uiTcpServer"
QT_MOC_LITERAL(1, 12, 12), // "ServerListen"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "ServerClose"
QT_MOC_LITERAL(4, 38, 11), // "ReceiveData"
QT_MOC_LITERAL(5, 50, 8), // "SendData"
QT_MOC_LITERAL(6, 59, 8), // "QString&"
QT_MOC_LITERAL(7, 68, 13), // "SendListCount"
QT_MOC_LITERAL(8, 82, 17), // "on_Listen_clicked"
QT_MOC_LITERAL(9, 100, 20), // "on_DisListen_clicked"
QT_MOC_LITERAL(10, 121, 19) // "on_Close_Ui_clicked"

    },
    "uiTcpServer\0ServerListen\0\0ServerClose\0"
    "ReceiveData\0SendData\0QString&\0"
    "SendListCount\0on_Listen_clicked\0"
    "on_DisListen_clicked\0on_Close_Ui_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiTcpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       7,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void uiTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiTcpServer *_t = static_cast<uiTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ServerListen(); break;
        case 1: _t->ServerClose(); break;
        case 2: _t->ReceiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SendListCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_Listen_clicked(); break;
        case 6: _t->on_DisListen_clicked(); break;
        case 7: _t->on_Close_Ui_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (uiTcpServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uiTcpServer::ServerListen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (uiTcpServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uiTcpServer::ServerClose)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (uiTcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uiTcpServer::ReceiveData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (uiTcpServer::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uiTcpServer::SendData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (uiTcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&uiTcpServer::SendListCount)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject uiTcpServer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_uiTcpServer.data,
      qt_meta_data_uiTcpServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *uiTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_uiTcpServer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int uiTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void uiTcpServer::ServerListen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void uiTcpServer::ServerClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void uiTcpServer::ReceiveData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void uiTcpServer::SendData(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void uiTcpServer::SendListCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
