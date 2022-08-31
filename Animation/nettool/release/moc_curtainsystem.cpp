/****************************************************************************
** Meta object code from reading C++ file 'curtainsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../form/curtainsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curtainsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurtainSystem_t {
    QByteArrayData data[20];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurtainSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurtainSystem_t qt_meta_stringdata_CurtainSystem = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CurtainSystem"
QT_MOC_LITERAL(1, 14, 9), // "SendClose"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "RadioBroadcast"
QT_MOC_LITERAL(4, 40, 19), // "on_BackMain_clicked"
QT_MOC_LITERAL(5, 60, 11), // "ButtonStyle"
QT_MOC_LITERAL(6, 72, 12), // "QPushButton*"
QT_MOC_LITERAL(7, 85, 4), // "Name"
QT_MOC_LITERAL(8, 90, 6), // "Offset"
QT_MOC_LITERAL(9, 97, 10), // "BlurRadius"
QT_MOC_LITERAL(10, 108, 13), // "on_Up_clicked"
QT_MOC_LITERAL(11, 122, 15), // "on_Stop_clicked"
QT_MOC_LITERAL(12, 138, 15), // "on_Down_clicked"
QT_MOC_LITERAL(13, 154, 15), // "ButtonStylePlan"
QT_MOC_LITERAL(14, 170, 14), // "SetInstruction"
QT_MOC_LITERAL(15, 185, 29), // "on_Device_Slider_valueChanged"
QT_MOC_LITERAL(16, 215, 5), // "value"
QT_MOC_LITERAL(17, 221, 34), // "on_horizontalSlider_2_valueCh..."
QT_MOC_LITERAL(18, 256, 11), // "ReceiveData"
QT_MOC_LITERAL(19, 268, 14) // "BrightnessShow"

    },
    "CurtainSystem\0SendClose\0\0RadioBroadcast\0"
    "on_BackMain_clicked\0ButtonStyle\0"
    "QPushButton*\0Name\0Offset\0BlurRadius\0"
    "on_Up_clicked\0on_Stop_clicked\0"
    "on_Down_clicked\0ButtonStylePlan\0"
    "SetInstruction\0on_Device_Slider_valueChanged\0"
    "value\0on_horizontalSlider_2_valueChanged\0"
    "ReceiveData\0BrightnessShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurtainSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   83,    2, 0x08 /* Private */,
       5,    3,   84,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    3,   94,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      15,    1,  104,    2, 0x08 /* Private */,
      17,    1,  107,    2, 0x08 /* Private */,
      18,    1,  110,    2, 0x0a /* Public */,
      19,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void CurtainSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurtainSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendClose(); break;
        case 1: _t->RadioBroadcast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_BackMain_clicked(); break;
        case 3: _t->ButtonStyle((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->on_Up_clicked(); break;
        case 5: _t->on_Stop_clicked(); break;
        case 6: _t->on_Down_clicked(); break;
        case 7: _t->ButtonStylePlan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->SetInstruction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_Device_Slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->ReceiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->BrightnessShow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CurtainSystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurtainSystem::SendClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CurtainSystem::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurtainSystem::RadioBroadcast)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CurtainSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CurtainSystem.data,
    qt_meta_data_CurtainSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurtainSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurtainSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurtainSystem.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CurtainSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CurtainSystem::SendClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CurtainSystem::RadioBroadcast(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
