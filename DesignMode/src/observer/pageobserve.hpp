#include "AbstractObserver.h"
#include "qwidget.h"
#include "qlabel.h"

class ObserverMoney : public QWidget, public AbstractObserver
{
public:
	ObserverMoney(QWidget *parent = nullptr);
	~ObserverMoney();
public:
	void update() override;
	void update(std::string info) override;

private:

	QLabel *lb;
};

ObserverMoney::ObserverMoney(QWidget * parent)
	:QWidget(parent)
{
	lb = new QLabel(this);
	lb->move(0, 0);
	lb->resize(200, 80);
}

ObserverMoney::~ObserverMoney()
{
}

void ObserverMoney::update()
{

}

void ObserverMoney::update(std::string info)
{
	lb->setText(QString(info.c_str()));
}

/**********************************************/

class ObserverVideo : public QWidget, public AbstractObserver
{
public:
	ObserverVideo(QWidget *parent = nullptr);
	~ObserverVideo();
public:
	void update() override;
	void update(std::string info) override;

private:

	QLabel *lb;
};

ObserverVideo::ObserverVideo(QWidget * parent)
	:QWidget(parent)
{
	lb = new QLabel(this);
	lb->move(0, 0);
	lb->resize(200, 80);
}

ObserverVideo::~ObserverVideo()
{
}

void ObserverVideo::update()
{

}

void ObserverVideo::update(std::string info)
{
	lb->setText(QString(info.c_str()));
}
/*********************************************************/

class ObserverWeather : public QWidget, public AbstractObserver
{
public:
	ObserverWeather(QWidget *parent = nullptr);
	~ObserverWeather();
public:
	void update() override;
	void update(std::string info) override;

private:

	QLabel *lb;
};

ObserverWeather::ObserverWeather(QWidget * parent)
	:QWidget(parent)
{
	lb = new QLabel(this);
	lb->move(0, 0);
	lb->resize(200, 80);
}

ObserverWeather::~ObserverWeather()
{
}

void ObserverWeather::update()
{

}

void ObserverWeather::update(std::string info)
{
	lb->setText(QString(info.c_str()));
}
