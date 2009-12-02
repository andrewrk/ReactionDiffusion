/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Dec 1 22:31:18 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      42,   36,   11,   11, 0x08,
      84,   36,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     150,   36,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     217,  211,   11,   11, 0x08,
     255,  211,   11,   11, 0x08,
     286,  211,   11,   11, 0x08,
     317,  211,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_text_s_textChanged()\0"
    "index\0on_combo_presets_currentIndexChanged(int)\0"
    "on_combo_frameSkip_currentIndexChanged(int)\0"
    "on_btn_next_clicked()\0"
    "on_combo_mode_currentIndexChanged(int)\0"
    "on_btn_draw_clicked()\0value\0"
    "on_slider_betaError_valueChanged(int)\0"
    "on_slider_Db_valueChanged(int)\0"
    "on_slider_Da_valueChanged(int)\0"
    "on_slider_s_valueChanged(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_text_s_textChanged(); break;
        case 1: on_combo_presets_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_combo_frameSkip_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_btn_next_clicked(); break;
        case 4: on_combo_mode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_btn_draw_clicked(); break;
        case 6: on_slider_betaError_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_slider_Db_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_slider_Da_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_slider_s_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
