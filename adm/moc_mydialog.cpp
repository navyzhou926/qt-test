/****************************************************************************
** Meta object code from reading C++ file 'mydialog.h'
**
** Created: Fri Mar 18 17:30:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mydialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      18,    9,    9,    9, 0x08,
      29,    9,    9,    9, 0x08,
      43,    9,    9,    9, 0x08,
      57,    9,    9,    9, 0x08,
      67,    9,    9,    9, 0x08,
      77,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyDialog[] = {
    "MyDialog\0\0enter()\0showTime()\0timeoutslot()\0"
    "showPicture()\0sendMsg()\0recvMsg()\0"
    "error()\0"
};

const QMetaObject MyDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MyDialog,
      qt_meta_data_MyDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyDialog))
        return static_cast<void*>(const_cast< MyDialog*>(this));
    if (!strcmp(_clname, "Ui_Form"))
        return static_cast< Ui_Form*>(const_cast< MyDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enter(); break;
        case 1: showTime(); break;
        case 2: timeoutslot(); break;
        case 3: showPicture(); break;
        case 4: sendMsg(); break;
        case 5: recvMsg(); break;
        case 6: error(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
