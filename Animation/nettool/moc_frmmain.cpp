/****************************************************************************
** Meta object code from reading C++ file 'frmmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/frmmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmMain_t {
    QByteArrayData data[21];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmMain_t qt_meta_stringdata_frmMain = {
    {
QT_MOC_LITERAL(0, 0, 7), // "frmMain"
QT_MOC_LITERAL(1, 8, 10), // "Show_SubUi"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 17), // "Show_Window_SubUi"
QT_MOC_LITERAL(4, 38, 8), // "SendData"
QT_MOC_LITERAL(5, 47, 12), // "ServerListen"
QT_MOC_LITERAL(6, 60, 11), // "ServerClose"
QT_MOC_LITERAL(7, 72, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(8, 100, 5), // "index"
QT_MOC_LITERAL(9, 106, 10), // "saveConfig"
QT_MOC_LITERAL(10, 117, 10), // "initConfig"
QT_MOC_LITERAL(11, 128, 21), // "on_UISreachIP_clicked"
QT_MOC_LITERAL(12, 150, 17), // "on_Server_clicked"
QT_MOC_LITERAL(13, 168, 17), // "on_GoMain_clicked"
QT_MOC_LITERAL(14, 186, 24), // "on_GoControlPage_clicked"
QT_MOC_LITERAL(15, 211, 24), // "on_CurtainSystem_clicked"
QT_MOC_LITERAL(16, 236, 21), // "on_DoorSystem_clicked"
QT_MOC_LITERAL(17, 258, 21), // "on_WindSystem_clicked"
QT_MOC_LITERAL(18, 280, 22), // "on_LightSystem_clicked"
QT_MOC_LITERAL(19, 303, 20), // "on_AirSystem_clicked"
QT_MOC_LITERAL(20, 324, 23) // "on_WindowSystem_clicked"

    },
    "frmMain\0Show_SubUi\0\0Show_Window_SubUi\0"
    "SendData\0ServerListen\0ServerClose\0"
    "on_tabWidget_currentChanged\0index\0"
    "saveConfig\0initConfig\0on_UISreachIP_clicked\0"
    "on_Server_clicked\0on_GoMain_clicked\0"
    "on_GoControlPage_clicked\0"
    "on_CurtainSystem_clicked\0on_DoorSystem_clicked\0"
    "on_WindSystem_clicked\0on_LightSystem_clicked\0"
    "on_AirSystem_clicked\0on_WindowSystem_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  109,    2, 0x08 /* Private */,
       9,    0,  112,    2, 0x08 /* Private */,
      10,    0,  113,    2, 0x08 /* Private */,
      11,    0,  114,    2, 0x08 /* Private */,
      12,    0,  115,    2, 0x08 /* Private */,
      13,    0,  116,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmMain *_t = static_cast<frmMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Show_SubUi(); break;
        case 1: _t->Show_Window_SubUi(); break;
        case 2: _t->SendData(); break;
        case 3: _t->ServerListen(); break;
        case 4: _t->ServerClose(); break;
        case 5: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->saveConfig(); break;
        case 7: _t->initConfig(); break;
        case 8: _t->on_UISreachIP_clicked(); break;
        case 9: _t->on_Server_clicked(); break;
        case 10: _t->on_GoMain_clicked(); break;
        case 11: _t->on_GoControlPage_clicked(); break;
        case 12: _t->on_CurtainSystem_clicked(); break;
        case 13: _t->on_DoorSystem_clicked(); break;
        case 14: _t->on_WindSystem_clicked(); break;
        case 15: _t->on_LightSystem_clicked(); break;
        case 16: _t->on_AirSystem_clicked(); break;
        case 17: _t->on_WindowSystem_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::Show_SubUi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::Show_Window_SubUi)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::SendData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::ServerListen)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::ServerClose)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmMain.data,
      qt_meta_data_frmMain,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *frmMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmMain.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void frmMain::Show_SubUi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmMain::Show_Window_SubUi()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void frmMain::SendData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void frmMain::ServerListen()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void frmMain::ServerClose()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
