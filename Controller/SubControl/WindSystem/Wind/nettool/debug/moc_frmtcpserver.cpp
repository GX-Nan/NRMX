/****************************************************************************
** Meta object code from reading C++ file 'frmtcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form/frmtcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmtcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmTcpServer_t {
    QByteArrayData data[22];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmTcpServer_t qt_meta_stringdata_frmTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmTcpServer"
QT_MOC_LITERAL(1, 13, 8), // "initForm"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "initIP"
QT_MOC_LITERAL(4, 30, 10), // "initConfig"
QT_MOC_LITERAL(5, 41, 10), // "saveConfig"
QT_MOC_LITERAL(6, 52, 11), // "changeTimer"
QT_MOC_LITERAL(7, 64, 6), // "append"
QT_MOC_LITERAL(8, 71, 4), // "type"
QT_MOC_LITERAL(9, 76, 4), // "data"
QT_MOC_LITERAL(10, 81, 5), // "clear"
QT_MOC_LITERAL(11, 87, 15), // "clientConnected"
QT_MOC_LITERAL(12, 103, 2), // "ip"
QT_MOC_LITERAL(13, 106, 4), // "port"
QT_MOC_LITERAL(14, 111, 18), // "clientDisconnected"
QT_MOC_LITERAL(15, 130, 8), // "sendData"
QT_MOC_LITERAL(16, 139, 11), // "receiveData"
QT_MOC_LITERAL(17, 151, 20), // "on_btnListen_clicked"
QT_MOC_LITERAL(18, 172, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(19, 191, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(20, 211, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(21, 230, 19) // "on_btnClose_clicked"

    },
    "frmTcpServer\0initForm\0\0initIP\0initConfig\0"
    "saveConfig\0changeTimer\0append\0type\0"
    "data\0clear\0clientConnected\0ip\0port\0"
    "clientDisconnected\0sendData\0receiveData\0"
    "on_btnListen_clicked\0on_btnSave_clicked\0"
    "on_btnClear_clicked\0on_btnSend_clicked\0"
    "on_btnClose_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmTcpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    3,   99,    2, 0x08 /* Private */,
       7,    2,  106,    2, 0x28 /* Private | MethodCloned */,
      11,    2,  111,    2, 0x08 /* Private */,
      14,    2,  116,    2, 0x08 /* Private */,
      15,    3,  121,    2, 0x08 /* Private */,
      16,    3,  128,    2, 0x08 /* Private */,
      17,    0,  135,    2, 0x08 /* Private */,
      18,    0,  136,    2, 0x08 /* Private */,
      19,    0,  137,    2, 0x08 /* Private */,
      20,    0,  138,    2, 0x08 /* Private */,
      21,    0,  139,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   12,   13,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   12,   13,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initForm(); break;
        case 1: _t->initIP(); break;
        case 2: _t->initConfig(); break;
        case 3: _t->saveConfig(); break;
        case 4: _t->changeTimer(); break;
        case 5: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->clientConnected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->clientDisconnected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->receiveData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 11: _t->on_btnListen_clicked(); break;
        case 12: _t->on_btnSave_clicked(); break;
        case 13: _t->on_btnClear_clicked(); break;
        case 14: _t->on_btnSend_clicked(); break;
        case 15: _t->on_btnClose_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmTcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_frmTcpServer.data,
    qt_meta_data_frmTcpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmTcpServer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
