/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created: Wed Jul 15 10:43:03 2015
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tcpServer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      19,   10,   11,   10, 0x08,
      33,   10,   10,   10, 0x08,
      55,   10,   10,   10, 0x08,
      75,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_tcpServer[] = {
    "tcpServer\0\0QString\0currentTime()\0"
    "changeString(QString)\0stopButtonClicked()\0"
    "continueButtonClicked()\0"
};

const QMetaObject tcpServer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tcpServer,
      qt_meta_data_tcpServer, 0 }
};

const QMetaObject *tcpServer::metaObject() const
{
    return &staticMetaObject;
}

void *tcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tcpServer))
	return static_cast<void*>(const_cast< tcpServer*>(this));
    return QWidget::qt_metacast(_clname);
}

int tcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = currentTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: changeString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: stopButtonClicked(); break;
        case 3: continueButtonClicked(); break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
