/****************************************************************************
** Meta object code from reading C++ file 'formCKC.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "formCKC.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formCKC.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_formCKC_t {
    QByteArrayData data[11];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_formCKC_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_formCKC_t qt_meta_stringdata_formCKC = {
    {
QT_MOC_LITERAL(0, 0, 7), // "formCKC"
QT_MOC_LITERAL(1, 8, 12), // "slot_pbBegin"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "slot_pbLeft"
QT_MOC_LITERAL(4, 34, 12), // "slot_pbRight"
QT_MOC_LITERAL(5, 47, 10), // "slot_pbEnd"
QT_MOC_LITERAL(6, 58, 20), // "slot_jrnChoseByTitle"
QT_MOC_LITERAL(7, 79, 21), // "slot_numsChoseByTitle"
QT_MOC_LITERAL(8, 101, 17), // "slot_lwrowChanged"
QT_MOC_LITERAL(9, 119, 18), // "slot_flushJournals"
QT_MOC_LITERAL(10, 138, 17) // "slot_flushNumbers"

    },
    "formCKC\0slot_pbBegin\0\0slot_pbLeft\0"
    "slot_pbRight\0slot_pbEnd\0slot_jrnChoseByTitle\0"
    "slot_numsChoseByTitle\0slot_lwrowChanged\0"
    "slot_flushJournals\0slot_flushNumbers"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_formCKC[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       7,    1,   66,    2, 0x08 /* Private */,
       8,    1,   69,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void formCKC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        formCKC *_t = static_cast<formCKC *>(_o);
        switch (_id) {
        case 0: _t->slot_pbBegin(); break;
        case 1: _t->slot_pbLeft(); break;
        case 2: _t->slot_pbRight(); break;
        case 3: _t->slot_pbEnd(); break;
        case 4: _t->slot_jrnChoseByTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slot_numsChoseByTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slot_lwrowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_flushJournals(); break;
        case 8: _t->slot_flushNumbers(); break;
        default: ;
        }
    }
}

const QMetaObject formCKC::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_formCKC.data,
      qt_meta_data_formCKC,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *formCKC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *formCKC::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_formCKC.stringdata))
        return static_cast<void*>(const_cast< formCKC*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int formCKC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
