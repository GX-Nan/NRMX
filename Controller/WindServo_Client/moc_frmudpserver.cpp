/****************************************************************************
** Meta object code from reading C++ file 'frmudpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/frmudpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmudpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmUdpServer_t {
    QByteArrayData data[20];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmUdpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmUdpServer_t qt_meta_stringdata_frmUdpServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmUdpServer"
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
QT_MOC_LITERAL(11, 87, 8), // "readData"
QT_MOC_LITERAL(12, 96, 8), // "sendData"
QT_MOC_LITERAL(13, 105, 2), // "ip"
QT_MOC_LITERAL(14, 108, 4), // "port"
QT_MOC_LITERAL(15, 113, 15), // "clientConnected"
QT_MOC_LITERAL(16, 129, 20), // "on_btnListen_clicked"
QT_MOC_LITERAL(17, 150, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(18, 169, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(19, 189, 18) // "on_btnSend_clicked"

    },
    "frmUdpServer\0initForm\0\0initIP\0initConfig\0"
    "saveConfig\0changeTimer\0append\0type\0"
    "data\0clear\0readData\0sendData\0ip\0port\0"
    "clientConnected\0on_btnListen_clicked\0"
    "on_btnSave_clicked\0on_btnClear_clicked\0"
    "on_btnSend_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmUdpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    3,   89,    2, 0x08 /* Private */,
       7,    2,   96,    2, 0x28 /* Private | MethodCloned */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    3,  102,    2, 0x08 /* Private */,
      15,    2,  109,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   13,   14,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmUdpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmUdpServer *_t = static_cast<frmUdpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initForm(); break;
        case 1: _t->initIP(); break;
        case 2: _t->initConfig(); break;
        case 3: _t->saveConfig(); break;
        case 4: _t->changeTimer(); break;
        case 5: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->readData(); break;
        case 8: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: _t->clientConnected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_btnListen_clicked(); break;
        case 11: _t->on_btnSave_clicked(); break;
        case 12: _t->on_btnClear_clicked(); break;
        case 13: _t->on_btnSend_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmUdpServer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmUdpServer.data,
      qt_meta_data_frmUdpServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *frmUdpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmUdpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmUdpServer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmUdpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
