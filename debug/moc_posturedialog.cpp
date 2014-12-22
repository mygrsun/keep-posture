/****************************************************************************
** Meta object code from reading C++ file 'posturedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../posturedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'posturedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PostureDialog_t {
    QByteArrayData data[17];
    char stringdata[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PostureDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PostureDialog_t qt_meta_stringdata_PostureDialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 11),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 13),
QT_MOC_LITERAL(4, 41, 9),
QT_MOC_LITERAL(5, 51, 16),
QT_MOC_LITERAL(6, 68, 4),
QT_MOC_LITERAL(7, 73, 9),
QT_MOC_LITERAL(8, 83, 8),
QT_MOC_LITERAL(9, 92, 13),
QT_MOC_LITERAL(10, 106, 4),
QT_MOC_LITERAL(11, 111, 18),
QT_MOC_LITERAL(12, 130, 27),
QT_MOC_LITERAL(13, 158, 23),
QT_MOC_LITERAL(14, 182, 13),
QT_MOC_LITERAL(15, 196, 12),
QT_MOC_LITERAL(16, 209, 12)
    },
    "PostureDialog\0scanPosture\0\0reScanPosture\0"
    "getResult\0Detectheadresult\0rest\0"
    "playCamer\0moveLine\0pauseBtnClick\0time\0"
    "pauseDetectTimeout\0pauseHalfOneHoueActionClick\0"
    "pauseOneHoueActionClick\0httpReadyRead\0"
    "httpFinished\0submitAdvise\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PostureDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a,
       3,    0,   80,    2, 0x0a,
       4,    1,   81,    2, 0x0a,
       7,    0,   84,    2, 0x0a,
       8,    0,   85,    2, 0x0a,
       9,    1,   86,    2, 0x0a,
       9,    0,   89,    2, 0x2a,
      11,    0,   90,    2, 0x0a,
      12,    0,   91,    2, 0x0a,
      13,    0,   92,    2, 0x0a,
      14,    0,   93,    2, 0x0a,
      15,    0,   94,    2, 0x0a,
      16,    0,   95,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PostureDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PostureDialog *_t = static_cast<PostureDialog *>(_o);
        switch (_id) {
        case 0: _t->scanPosture(); break;
        case 1: _t->reScanPosture(); break;
        case 2: _t->getResult((*reinterpret_cast< Detectheadresult(*)>(_a[1]))); break;
        case 3: _t->playCamer(); break;
        case 4: _t->moveLine(); break;
        case 5: _t->pauseBtnClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->pauseBtnClick(); break;
        case 7: _t->pauseDetectTimeout(); break;
        case 8: _t->pauseHalfOneHoueActionClick(); break;
        case 9: _t->pauseOneHoueActionClick(); break;
        case 10: _t->httpReadyRead(); break;
        case 11: _t->httpFinished(); break;
        case 12: _t->submitAdvise(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Detectheadresult >(); break;
            }
            break;
        }
    }
}

const QMetaObject PostureDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PostureDialog.data,
      qt_meta_data_PostureDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *PostureDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PostureDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PostureDialog.stringdata))
        return static_cast<void*>(const_cast< PostureDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PostureDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
