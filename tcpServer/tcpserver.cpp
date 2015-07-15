#include "tcpserver.h"
#include <windows.h>


tcpServer::tcpServer(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);

	//setFixedSize(350,80);

	statusLabel = new QLabel(tr("It's the tcp server ~"));
	closeButton = new QPushButton(tr("Close"));
	stopButton = new QPushButton(tr("Stop"));
	continueButton = new QPushButton(tr("Continue"));
	textEdit = new QTextEdit(this);
	//stopButton->setEnabled(false);
	//continueButton->setEnabled(false);

	mainLayout = new QGridLayout(this);

	mainLayout->addWidget(statusLabel,0,0);
	mainLayout->addWidget(closeButton,0,1);
	mainLayout->addWidget(stopButton,0,2);
	mainLayout->addWidget(continueButton,0,3);
	mainLayout->addWidget(textEdit,1,0,3,4);
	setLayout(mainLayout);

	//statusLabel->setText("It's the tcp server ~");

	m_tcpServer = new QTcpServer(this);
	
	if(!m_tcpServer->listen(QHostAddress::LocalHost,23333))
	{
		qDebug() << m_tcpServer->errorString();
		close();
	}

	//connect(m_tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
	connect(m_tcpServer,SIGNAL(newConnection()),&m_thread,SLOT(start()));
	connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
	connect(&m_thread,SIGNAL(stringChanged(const QString&)),this,SLOT(changeString(const QString&)));
	//connect(stopButton,SIGNAL(clicked()),&m_thread,SLOT(stopButtonClicked()));
	connect(stopButton,SIGNAL(clicked()),this,SLOT(stopButtonClicked()));
	connect(continueButton,SIGNAL(clicked()),this,SLOT(continueButtonClicked()));
}

tcpServer::~tcpServer()
{
	
}

/*void tcpServer::sendMessage()
{
	QByteArray block;
	
	QDataStream out(&block,QIODevice::WriteOnly);

	out.setVersion(QDataStream::Qt_4_4);

	QTcpSocket *clientConnection = m_tcpServer->nextPendingConnection();
	connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));

	out << (quint16)0;
	out << currentTime() + tr("\n") + tr("hello world !");
	out.device()->seek(0);
	out << (quint16)(block.size()-sizeof(quint16));

	clientConnection->write(block);

	statusLabel->setText("Send message successful !");

}*/

QString tcpServer::currentTime()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
 	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	return current_date;
}

void tcpServer::changeString(const QString& str)
{
	textEdit->append(currentTime());
	textEdit->append(str);
}

void tcpServer::stopButtonClicked()
{
	m_thread.pause.lock();
	stopButton->setEnabled(false);
	continueButton->setEnabled(true);
}

void tcpServer::continueButtonClicked()
{
	m_thread.pause.unlock();
	stopButton->setEnabled(true);
	continueButton->setEnabled(false);
}