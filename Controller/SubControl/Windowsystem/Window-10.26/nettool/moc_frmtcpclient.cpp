/****************************************************************************
** Meta object code from reading C++ file 'frmtcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/frmtcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmtcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmTcpClient_t {
    QByteArrayData data[26];
    char stringdata0[288];
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
QT_MOC_LITERAL(5, 45, 14), // "Updata_Curtain"
QT_MOC_LITERAL(6, 60, 13), // "Updata_Window"
QT_MOC_LITERAL(7, 74, 8), // "initForm"
QT_MOC_LITERAL(8, 83, 10), // "initConfig"
QT_MOC_LITERAL(9, 94, 10), // "saveConfig"
QT_MOC_LITERAL(10, 105, 11), // "changeTimer"
QT_MOC_LITERAL(11, 117, 6), // "append"
QT_MOC_LITERAL(12, 124, 4), // "type"
QT_MOC_LITERAL(13, 129, 4), // "data"
QT_MOC_LITERAL(14, 134, 5), // "clear"
QT_MOC_LITERAL(15, 140, 9), // "connected"
QT_MOC_LITERAL(16, 150, 12), // "disconnected"
QT_MOC_LITERAL(17, 163, 8), // "readData"
QT_MOC_LITERAL(18, 172, 13), // "ClientConnect"
QT_MOC_LITERAL(19, 186, 16), // "ClientDisconnect"
QT_MOC_LITERAL(20, 203, 8), // "sendData"
QT_MOC_LITERAL(21, 212, 14), // "RadioBroadcast"
QT_MOC_LITERAL(22, 227, 17), // "Analysis_Curtains"
QT_MOC_LITERAL(23, 245, 15), // "Analysis_Window"
QT_MOC_LITERAL(24, 261, 14), // "RecoverSignals"
QT_MOC_LITERAL(25, 276, 11) // "StopSignals"

    },
    "frmTcpClient\0TextClear\0\0TextColor\0"
    "TextAppend\0Updata_Curtain\0Updata_Window\0"
    "initForm\0initConfig\0saveConfig\0"
    "changeTimer\0append\0type\0data\0clear\0"
    "connected\0disconnected\0readData\0"
    "ClientConnect\0ClientDisconnect\0sendData\0"
    "RadioBroadcast\0Analysis_Curtains\0"
    "Analysis_Window\0RecoverSignals\0"
    "StopSignals"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmTcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    1,  125,    2, 0x06 /* Public */,
       4,    1,  128,    2, 0x06 /* Public */,
       5,    2,  131,    2, 0x06 /* Public */,
       6,    2,  136,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  141,    2, 0x08 /* Private */,
       8,    0,  142,    2, 0x08 /* Private */,
       9,    0,  143,    2, 0x08 /* Private */,
      10,    0,  144,    2, 0x08 /* Private */,
      11,    3,  145,    2, 0x08 /* Private */,
      11,    2,  152,    2, 0x28 /* Private | MethodCloned */,
      15,    0,  157,    2, 0x08 /* Private */,
      16,    0,  158,    2, 0x08 /* Private */,
      17,    0,  159,    2, 0x08 /* Private */,
      18,    0,  160,    2, 0x0a /* Public */,
      19,    0,  161,    2, 0x0a /* Public */,
      20,    1,  162,    2, 0x0a /* Public */,
      21,    1,  165,    2, 0x0a /* Public */,
      22,    1,  168,    2, 0x0a /* Public */,
      23,    1,  171,    2, 0x0a /* Public */,
      24,    0,  174,    2, 0x0a /* Public */,
      25,    0,  175,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   12,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmTcpClient *_t = static_cast<frmTcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TextClear(); break;
        case 1: _t->TextColor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->TextAppend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Updata_Curtain((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->Updata_Window((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->initForm(); break;
        case 6: _t->initConfig(); break;
        case 7: _t->saveConfig(); break;
        case 8: _t->changeTimer(); break;
        case 9: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->append((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->connected(); break;
        case 12: _t->disconnected(); break;
        case 13: _t->readData(); break;
        case 14: _t->ClientConnect(); break;
        case 15: _t->ClientDisconnect(); break;
        case 16: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->RadioBroadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->Analysis_Curtains((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->Analysis_Window((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->RecoverSignals(); break;
        case 21: _t->StopSignals(); break;
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
        {
            using _t = void (frmTcpClient::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmTcpClient::Updata_Curtain)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (frmTcpClient::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmTcpClient::Updata_Window)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmTcpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_frmTcpClient.data,
      qt_meta_data_frmTcpClient,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void frmTcpClient::TextAppend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void frmTcpClient::Updata_Curtain(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void frmTcpClient::Updata_Window(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
