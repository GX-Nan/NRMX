/****************************************************************************
** Meta object code from reading C++ file 'frmtcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nettool/form/frmtcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmtcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmTcpClient_t {
    QByteArrayData data[19];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmTcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmTcpClient_t qt_meta_stringdata_frmTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmTcpClient"
QT_MOC_LITERAL(1, 13, 9), // "TextClear"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "TextColor"
QT_MOC_LITERAL(4, 34, 10), // "TextAppend"
QT_MOC_LITERAL(5, 45, 8), // "initForm"
QT_MOC_LITERAL(6, 54, 10), // "initConfig"
QT_MOC_LITERAL(7, 65, 10), // "saveConfig"
QT_MOC_LITERAL(8, 76, 11), // "changeTimer"
QT_MOC_LITERAL(9, 88, 6), // "append"
QT_MOC_LITERAL(10, 95, 4), // "type"
QT_MOC_LITERAL(11, 100, 4), // "data"
QT_MOC_LITERAL(12, 105, 5), // "clear"
QT_MOC_LITERAL(13, 111, 9), // "connected"
QT_MOC_LITERAL(14, 121, 12), // "disconnected"
QT_MOC_LITERAL(15, 134, 8), // "readData"
QT_MOC_LITERAL(16, 143, 13), // "ClientConnect"
QT_MOC_LITERAL(17, 157, 16), // "ClientDisconnect"
QT_MOC_LITERAL(18, 174, 8) // "sendData"

    },
    "frmTcpClient\0TextClear\0\0TextColor\0"
    "TextAppend\0initForm\0initConfig\0"
    "saveConfig\0changeTimer\0append\0type\0"
    "data\0clear\0connected\0disconnected\0"
    "readData\0ClientConnect\0ClientDisconnect\0"
    "sendData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmTcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       4,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   96,    2, 0x08 /* Private */,
       6,    0,   97,    2, 0x08 /* Private */,
       7,    0,   98,    2, 0x08 /* Private */,
       8,    0,   99,    2, 0x08 /* Private */,
       9,    3,  100,    2, 0x08 /* Private */,
       9,    2,  107,    2, 0x28 /* Private | MethodCloned */,
      13,    0,  112,    2, 0x08 /* Private */,
      14,    0,  113,    2, 0x08 /* Private */,
      15,    0,  114,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x0a /* Public */,
      17,    0,  116,    2, 0x0a /* Public */,
      18,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   10,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void frmTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmTcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TextClear(); break;
        case 1: _t->TextColor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->TextAppend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->initForm(); break;
        case 4: _t->initConfig(); break;
        case 5: _t->saveConfig(); break;
        case 6: _t->changeTimer(); break;
        case 7: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->connected(); break;
        case 10: _t->disconnected(); break;
        case 11: _t->readData(); break;
        case 12: _t->ClientConnect(); break;
        case 13: _t->ClientDisconnect(); break;
        case 14: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmTcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmTcpClient::TextClear)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmTcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmTcpClient::TextColor)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmTcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmTcpClient::TextAppend)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmTcpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_frmTcpClient.data,
    qt_meta_data_frmTcpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmTcpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int frmTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void frmTcpClient::TextClear()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmTcpClient::TextColor(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void frmTcpClient::TextAppend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
