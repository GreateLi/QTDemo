/****************************************************************************
** Meta object code from reading C++ file 'ToolBarSlice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ToolBarSlice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ToolBarSlice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToolBarSlice_t {
    QByteArrayData data[13];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolBarSlice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolBarSlice_t qt_meta_stringdata_ToolBarSlice = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ToolBarSlice"
QT_MOC_LITERAL(1, 13, 11), // "changeSlice"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "slice"
QT_MOC_LITERAL(4, 32, 4), // "text"
QT_MOC_LITERAL(5, 37, 12), // "changeToPrev"
QT_MOC_LITERAL(6, 50, 12), // "changeToNext"
QT_MOC_LITERAL(7, 63, 9), // "onPointer"
QT_MOC_LITERAL(8, 73, 9), // "onOverlay"
QT_MOC_LITERAL(9, 83, 7), // "onClear"
QT_MOC_LITERAL(10, 91, 7), // "onPoint"
QT_MOC_LITERAL(11, 99, 6), // "onLine"
QT_MOC_LITERAL(12, 106, 21) // "onCurrentIndexChanged"

    },
    "ToolBarSlice\0changeSlice\0\0slice\0text\0"
    "changeToPrev\0changeToNext\0onPointer\0"
    "onOverlay\0onClear\0onPoint\0onLine\0"
    "onCurrentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolBarSlice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x09 /* Protected */,
       1,    1,   67,    2, 0x09 /* Protected */,
       5,    0,   70,    2, 0x09 /* Protected */,
       6,    0,   71,    2, 0x09 /* Protected */,
       7,    1,   72,    2, 0x09 /* Protected */,
       8,    1,   75,    2, 0x09 /* Protected */,
       9,    0,   78,    2, 0x09 /* Protected */,
      10,    0,   79,    2, 0x09 /* Protected */,
      11,    0,   80,    2, 0x09 /* Protected */,
      12,    1,   81,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ToolBarSlice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolBarSlice *_t = static_cast<ToolBarSlice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeSlice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeSlice((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->changeToPrev(); break;
        case 3: _t->changeToNext(); break;
        case 4: _t->onPointer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onOverlay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onClear(); break;
        case 7: _t->onPoint(); break;
        case 8: _t->onLine(); break;
        case 9: _t->onCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ToolBarSlice::staticMetaObject = {
    { &ToolBar::staticMetaObject, qt_meta_stringdata_ToolBarSlice.data,
      qt_meta_data_ToolBarSlice,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ToolBarSlice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolBarSlice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBarSlice.stringdata0))
        return static_cast<void*>(this);
    return ToolBar::qt_metacast(_clname);
}

int ToolBarSlice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
