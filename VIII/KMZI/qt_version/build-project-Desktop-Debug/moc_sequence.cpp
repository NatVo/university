/****************************************************************************
** Meta object code from reading C++ file 'sequence.h'
**
<<<<<<< HEAD
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
=======
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/sequence.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sequence.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
<<<<<<< HEAD
#error "This file was generated using the moc from 5.9.2. It"
=======
#error "This file was generated using the moc from 5.5.1. It"
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
<<<<<<< HEAD
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
=======
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
struct qt_meta_stringdata_Sequence_t {
    QByteArrayData data[4];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sequence_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sequence_t qt_meta_stringdata_Sequence = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Sequence"
QT_MOC_LITERAL(1, 9, 11), // "startWindow"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 21) // "on_ButtonBack_clicked"

    },
    "Sequence\0startWindow\0\0on_ButtonBack_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sequence[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Sequence::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sequence *_t = static_cast<Sequence *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startWindow(); break;
        case 1: _t->on_ButtonBack_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Sequence::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sequence::startWindow)) {
                *result = 0;
<<<<<<< HEAD
                return;
=======
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Sequence::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Sequence.data,
<<<<<<< HEAD
      qt_meta_data_Sequence,  qt_static_metacall, nullptr, nullptr}
=======
      qt_meta_data_Sequence,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
};


const QMetaObject *Sequence::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sequence::qt_metacast(const char *_clname)
{
<<<<<<< HEAD
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sequence.stringdata0))
        return static_cast<void*>(this);
=======
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Sequence.stringdata0))
        return static_cast<void*>(const_cast< Sequence*>(this));
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
    return QWidget::qt_metacast(_clname);
}

int Sequence::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Sequence::startWindow()
{
<<<<<<< HEAD
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
=======
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
>>>>>>> f3449e4ae7da1a9847e16ca4acfae0a56db57005
QT_END_MOC_NAMESPACE
