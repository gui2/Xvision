/****************************************************************************
** Meta object code from reading C++ file 'ConfigDialog.h'
**
** Created: Tue Nov 19 13:48:16 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ConfigDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      38,   13,   13,   13, 0x08,
      62,   13,   13,   13, 0x08,
      98,   13,   13,   13, 0x08,
     132,   13,   13,   13, 0x08,
     169,   13,   13,   13, 0x08,
     203,   13,   13,   13, 0x08,
     245,  237,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigDialog[] = {
    "ConfigDialog\0\0on_buttonBox_rejected()\0"
    "on_buttonBox_accepted()\0"
    "on_pushButton_printTiming_clicked()\0"
    "on_pushButton_outputDir_clicked()\0"
    "on_pushButton_printResults_clicked()\0"
    "on_pushButton_modelPath_clicked()\0"
    "on_pushButton_imagePath_clicked()\0"
    "element\0on_comboBox_method_activated(QString)\0"
};

const QMetaObject ConfigDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigDialog,
      qt_meta_data_ConfigDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigDialog))
        return static_cast<void*>(const_cast< ConfigDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonBox_rejected(); break;
        case 1: on_buttonBox_accepted(); break;
        case 2: on_pushButton_printTiming_clicked(); break;
        case 3: on_pushButton_outputDir_clicked(); break;
        case 4: on_pushButton_printResults_clicked(); break;
        case 5: on_pushButton_modelPath_clicked(); break;
        case 6: on_pushButton_imagePath_clicked(); break;
        case 7: on_comboBox_method_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
