/********************************************************************************
** Form generated from reading ui file 'tcpserver.ui'
**
** Created: Wed Jul 15 10:43:03 2015
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcpServerClass
{
public:

    void setupUi(QWidget *tcpServerClass)
    {
    if (tcpServerClass->objectName().isEmpty())
        tcpServerClass->setObjectName(QString::fromUtf8("tcpServerClass"));
    tcpServerClass->resize(600, 400);

    retranslateUi(tcpServerClass);

    QMetaObject::connectSlotsByName(tcpServerClass);
    } // setupUi

    void retranslateUi(QWidget *tcpServerClass)
    {
    tcpServerClass->setWindowTitle(QApplication::translate("tcpServerClass", "tcpServer", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(tcpServerClass);
    } // retranslateUi

};

namespace Ui {
    class tcpServerClass: public Ui_tcpServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
