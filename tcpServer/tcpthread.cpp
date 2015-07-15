#include "tcpthread.h"
#include <QDebug>

tcpThread::tcpThread(QObject *parent)
	: QThread(parent)
{
	stopped = false ;
}

tcpThread::~tcpThread()
{

}

void tcpThread::run()
{
	QFile f("D:\\Desktop\\research\\data.txt");  
	
	if(!f.open(QIODevice::ReadOnly | QIODevice::Text))  
	{  
	    qDebug() << "Open file failed." << endl;  
	    return ;  
	}  
/*******************************************Server test******************************************/ 
	
	QTextStream txtInput(&f);  
	QString lineStr;  
	
	while((!stopped)&&(!txtInput.atEnd()))  
	{  
	    qDebug() << stopped;

	    pause.lock();
		
		lineStr = txtInput.readLine();
	    emit stringChanged(lineStr);
	    msleep(1000);

	    pause.unlock();
	}
/*******************************************Server test******************************************/	
/*******************************************Server test******************************************/	
/*
	QByteArray block;
	QDataStream out(&block,QIODevice::WriteOnly);

	out.setVersion(QDataStream::Qt_4_4);

	QTcpSocket *clientConnection = p_tcpServer.nextPendingConnection();
	connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));

	QTextStream txtInput(&f);  
	QString lineStr;  
	
	while(!txtInput.atEnd())  
	{  
	    pause.lock();

	    lineStr = txtInput.readLine(); 
	    
		out << (quint16)0;
		out << currentTime() + tr("\n") + lineStr;
		out.device()->seek(0);
		out << (quint16)(block.size()-sizeof(quint16));

	    clientConnection->write(block); 
	    emit stringChanged(lineStr);
	    block.clear();

	    msleep(1000);

	    pause.unlock();
	}  
	  
	f.close(); 
	stop();
	*/
}
void tcpThread::stop()
{
	stopped = true;
}
/*void tcpThread::stopButtonClicked()
{
	
}*/

QString tcpThread::currentTime()
{
	QDateTime current_date_time = QDateTime::currentDateTime();
 	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	return current_date;
}