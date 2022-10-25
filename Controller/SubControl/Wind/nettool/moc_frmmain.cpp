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
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmMain_t qt_meta_stringdata_frmMain = {
    {
QT_MOC_LITERAL(0, 0, 7), // "frmMain"
QT_MOC_LITERAL(1, 8, 14), // "ShowUiSreachIP"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "ExecUiSreachIP"
QT_MOC_LITERAL(4, 39, 13), // "ClientConnect"
QT_MOC_LITERAL(5, 53, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(6, 81, 5), // "index"
QT_MOC_LITERAL(7, 87, 10), // "saveConfig"
QT_MOC_LITERAL(8, 98, 10), // "initConfig"
QT_MOC_LITERAL(9, 109, 21), // "on_UISreachIP_clicked"
QT_MOC_LITERAL(10, 131, 12) // "ClientConfig"

    },
    "frmMain\0ShowUiSreachIP\0\0ExecUiSreachIP\0"
    "ClientConnect\0on_tabWidget_currentChanged\0"
    "index\0saveConfig\0initConfig\0"
    "on_UISreachIP_clicked\0ClientConfig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   57,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
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
        case 0: _t->ShowUiSreachIP(); break;
        case 1: _t->ExecUiSreachIP(); break;
        case 2: _t->ClientConnect(); break;
        case 3: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->saveConfig(); break;
        case 5: _t->initConfig(); break;
        case 6: _t->on_UISreachIP_clicked(); break;
        case 7: _t->ClientConfig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::ShowUiSreachIP)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::ExecUiSreachIP)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (frmMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmMain::ClientConnect)) {
                *result = 2;
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
void frmMain::ShowUiSreachIP()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmMain::ExecUiSreachIP()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void frmMain::ClientConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
