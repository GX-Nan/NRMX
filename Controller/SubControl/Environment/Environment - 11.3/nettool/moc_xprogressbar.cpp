/****************************************************************************
** Meta object code from reading C++ file 'xprogressbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "form/xprogressbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xprogressbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XProgressBar_t {
    QByteArrayData data[20];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XProgressBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XProgressBar_t qt_meta_stringdata_XProgressBar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "XProgressBar"
QT_MOC_LITERAL(1, 13, 13), // "setValueBrush"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "valueBrush"
QT_MOC_LITERAL(4, 39, 13), // "setValueColor"
QT_MOC_LITERAL(5, 53, 10), // "valueColor"
QT_MOC_LITERAL(6, 64, 10), // "setBgColor"
QT_MOC_LITERAL(7, 75, 7), // "bgColor"
QT_MOC_LITERAL(8, 83, 12), // "setTextColor"
QT_MOC_LITERAL(9, 96, 9), // "textColor"
QT_MOC_LITERAL(10, 106, 9), // "setRadius"
QT_MOC_LITERAL(11, 116, 6), // "radius"
QT_MOC_LITERAL(12, 123, 13), // "setAutoRadius"
QT_MOC_LITERAL(13, 137, 10), // "autoRadius"
QT_MOC_LITERAL(14, 148, 21), // "setShowProgressRadius"
QT_MOC_LITERAL(15, 170, 18), // "showProgressRadius"
QT_MOC_LITERAL(16, 189, 14), // "setBorderWidth"
QT_MOC_LITERAL(17, 204, 11), // "borderWidth"
QT_MOC_LITERAL(18, 216, 14), // "setBorderColor"
QT_MOC_LITERAL(19, 231, 11) // "borderColor"

    },
    "XProgressBar\0setValueBrush\0\0valueBrush\0"
    "setValueColor\0valueColor\0setBgColor\0"
    "bgColor\0setTextColor\0textColor\0setRadius\0"
    "radius\0setAutoRadius\0autoRadius\0"
    "setShowProgressRadius\0showProgressRadius\0"
    "setBorderWidth\0borderWidth\0setBorderColor\0"
    "borderColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XProgressBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       9,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      14,    1,   77,    2, 0x0a /* Public */,
      16,    1,   80,    2, 0x0a /* Public */,
      18,    1,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QBrush,    3,
    QMetaType::Void, QMetaType::QColor,    5,
    QMetaType::Void, QMetaType::QColor,    7,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::QColor,   19,

 // properties: name, type, flags
       3, QMetaType::QBrush, 0x00095103,
       5, QMetaType::QColor, 0x00095103,
       7, QMetaType::QColor, 0x00095103,
       9, QMetaType::QColor, 0x00095103,
      11, QMetaType::Int, 0x00095103,
      13, QMetaType::Bool, 0x00095103,
      15, QMetaType::Bool, 0x00095103,
      17, QMetaType::Double, 0x00095103,
      19, QMetaType::QColor, 0x00095103,

       0        // eod
};

void XProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XProgressBar *_t = static_cast<XProgressBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setValueBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 1: _t->setValueColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->setBgColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->setTextColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->setRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setAutoRadius((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setShowProgressRadius((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setBorderWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setBorderColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        XProgressBar *_t = static_cast<XProgressBar *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QBrush*>(_v) = _t->getValueBrush(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getValueColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getBgColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->getTextColor(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getRadius(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->getAutoRadius(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->getShowProgressRadius(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->getBorderWidth(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getBorderColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        XProgressBar *_t = static_cast<XProgressBar *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValueBrush(*reinterpret_cast< QBrush*>(_v)); break;
        case 1: _t->setValueColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setRadius(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setAutoRadius(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setShowProgressRadius(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setBorderWidth(*reinterpret_cast< double*>(_v)); break;
        case 8: _t->setBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject XProgressBar::staticMetaObject = {
    { &QProgressBar::staticMetaObject, qt_meta_stringdata_XProgressBar.data,
      qt_meta_data_XProgressBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *XProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XProgressBar.stringdata0))
        return static_cast<void*>(this);
    return QProgressBar::qt_metacast(_clname);
}

int XProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProgressBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
