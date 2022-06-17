/****************************************************************************
** Meta object code from reading C++ file 'ActivedSignalCfg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ActivedSignalCfg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ActivedSignalCfg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_activeSignalCfg__CActivedSignalCfg_t {
    QByteArrayData data[10];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_activeSignalCfg__CActivedSignalCfg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_activeSignalCfg__CActivedSignalCfg_t qt_meta_stringdata_activeSignalCfg__CActivedSignalCfg = {
    {
QT_MOC_LITERAL(0, 0, 34), // "activeSignalCfg::CActivedSign..."
QT_MOC_LITERAL(1, 35, 37), // "InPutChangedCallbackof_spinBo..."
QT_MOC_LITERAL(2, 73, 0), // ""
QT_MOC_LITERAL(3, 74, 37), // "InPutChangedCallbackof_spinBo..."
QT_MOC_LITERAL(4, 112, 7), // "SaveCfg"
QT_MOC_LITERAL(5, 120, 9), // "SaveCfgAs"
QT_MOC_LITERAL(6, 130, 7), // "OpenCfg"
QT_MOC_LITERAL(7, 138, 6), // "Cancel"
QT_MOC_LITERAL(8, 145, 24), // "CallfunctoChannelChanged"
QT_MOC_LITERAL(9, 170, 17) // "ApplyToAllChannel"

    },
    "activeSignalCfg::CActivedSignalCfg\0"
    "InPutChangedCallbackof_spinBoxVoltage\0"
    "\0InPutChangedCallbackof_spinBoxCurrent\0"
    "SaveCfg\0SaveCfgAs\0OpenCfg\0Cancel\0"
    "CallfunctoChannelChanged\0ApplyToAllChannel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_activeSignalCfg__CActivedSignalCfg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void activeSignalCfg::CActivedSignalCfg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CActivedSignalCfg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InPutChangedCallbackof_spinBoxVoltage(); break;
        case 1: _t->InPutChangedCallbackof_spinBoxCurrent(); break;
        case 2: { bool _r = _t->SaveCfg();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->SaveCfgAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->OpenCfg();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->Cancel(); break;
        case 6: _t->CallfunctoChannelChanged(); break;
        case 7: _t->ApplyToAllChannel(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject activeSignalCfg::CActivedSignalCfg::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_activeSignalCfg__CActivedSignalCfg.data,
    qt_meta_data_activeSignalCfg__CActivedSignalCfg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *activeSignalCfg::CActivedSignalCfg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *activeSignalCfg::CActivedSignalCfg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_activeSignalCfg__CActivedSignalCfg.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int activeSignalCfg::CActivedSignalCfg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
