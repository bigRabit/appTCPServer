#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QFile>
#include <QMutex>
#include <QtNetWork>
#include <QTcpServer>

class tcpThread : public QThread
{
	Q_OBJECT

public:
	explicit tcpThread(QObject *parent = 0);
	~tcpThread();
	void stop();
	QMutex pause;

protected:
	void run();

private:
	volatile bool stopped;
	QString currentTime();

signals:
	void stringChanged(const QString&);
/*public slots:
	void stopButtonClicked();*/
};

#endif // TCPTHREAD_H
