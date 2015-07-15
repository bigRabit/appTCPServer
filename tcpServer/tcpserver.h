#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtGui/QWidget>
#include "ui_tcpserver.h"
#include <QLabel>
#include <QtNetWork>
#include <QTcpServer>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include "tcpthread.h"

class tcpServer : public QWidget
{
	Q_OBJECT

public:
	tcpServer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~tcpServer();

private:
	Ui::tcpServerClass ui;
	QLabel *statusLabel;
	QTcpServer *m_tcpServer;
	QGridLayout *mainLayout;
	QPushButton *closeButton;
	QTextEdit *textEdit;
	tcpThread m_thread;
	QPushButton *stopButton;
	QPushButton *continueButton;

private slots:
	//void sendMessage();
	QString currentTime();
	void changeString(const QString&);
	void stopButtonClicked();
	void continueButtonClicked();
	//void closeButtonClicked();
};

#endif // TCPSERVER_H
