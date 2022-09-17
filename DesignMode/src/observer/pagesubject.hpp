#include "AbstractSubject.h"
#include <qwidget.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include "pageobserve.hpp"

#define GB(str) QString::fromLocal8Bit(#str)
class SubjectA : public QWidget, public AbstractSubject
{
public:
	SubjectA(QWidget *parent = nullptr);
	~SubjectA();

	void timerEvent(QTimerEvent *e);

public:
	void attach(AbstractObserver* observer) override;

	void detach(AbstractObserver* observer) override;

	void notify() override;

private:

	QList<AbstractObserver*> m_observerList;
	int m_timer[3] = { 0 };
	std::string m_info1;
	std::string m_info2;
	std::string m_info3;
};



SubjectA::SubjectA(QWidget * parent) :
	QWidget(parent)
{
	QPushButton *pbMoney = new QPushButton(GB(金额));
	pbMoney->setObjectName("pbMoney");
	QPushButton *pbVideo = new QPushButton(GB(节目更新));
	pbVideo->setObjectName("pbVideo");
	QPushButton *pbWeather = new QPushButton(GB(天气));
	pbWeather->setObjectName("pbWeather");

	QVBoxLayout *lay = new QVBoxLayout;
	lay->addWidget(pbMoney);
	lay->addWidget(pbVideo);
	lay->addWidget(pbWeather);
	lay->setSpacing(1);

	ObserverMoney *sbMoney = new ObserverMoney;
	sbMoney->setStyleSheet("background-color:rgba(11,12,13,100);"
							"font-size:16px;"
							"color:red;");
	sbMoney->setObjectName("Money");
	ObserverVideo *sbVideo = new ObserverVideo;
	sbVideo->setStyleSheet("background-color:rgba(51,52,53,100);"
							"font-size:18px;"
							"color:yellow;");
	sbVideo->setObjectName("Vodeo");
	ObserverWeather *sbWeather = new ObserverWeather;
	sbWeather->setStyleSheet("background-color:rgba(91,92,93,100);"
							"font-size:20px;"
							"color:green;");
	sbWeather->setObjectName("weather");

	//添加观察者
	attach(sbMoney);
	attach(sbVideo);
	attach(sbWeather);

	QVBoxLayout *layRight = new QVBoxLayout;
	layRight->addWidget(sbMoney);
	layRight->addWidget(sbVideo);
	layRight->addWidget(sbWeather);
	layRight->setSpacing(1);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(lay);
	mainLayout->addLayout(layRight);
	mainLayout->setSpacing(1);
	this->setLayout(mainLayout);

	//启动观察对象
	m_timer[0] = startTimer(1000);
	m_timer[1] = startTimer(1500);
	m_timer[2] = startTimer(2000);
	m_info1 = (std::string("null"));
	m_info2 = (std::string("null"));
	m_info3 = (std::string("null"));
}

SubjectA::~SubjectA()
{
	//QObjectList li = >findChild
}

void SubjectA::timerEvent(QTimerEvent * e)
{
	if (e->timerId() == m_timer[0]) {
		static int money = 0;
		money += 124;
		QPushButton *btn = findChild<QPushButton*>("pbMoney");
		if (btn) {
			btn->setText(GB(金币余额 %1).arg(money));
			m_info1 = btn->text().toStdString();
		}
			
		notify();
	}
	else if (e->timerId() == m_timer[1]) {
		static int video = 0;
		video += 1;
		QPushButton *btn = findChild<QPushButton*>("pbVideo");
		if (btn) {
			btn->setText(GB(节目更新到 %1 集).arg(video));
			m_info2 = btn->text().toStdString();
		}
			
		notify();
	}
	else if (e->timerId() == m_timer[2]) {
		static int c = 0;
		c += 2;
		c *= 8;
		c %= 120;
		QPushButton *btn = findChild<QPushButton*>("pbWeather");
		if (btn) {
			btn->setText(GB(天气指数 %1).arg(c));
			m_info3 = btn->text().toStdString();
		}
			

		notify();
	}
}

void SubjectA::attach(AbstractObserver * observer)
{
	m_observerList.append(observer);
}

void SubjectA::detach(AbstractObserver * observer)
{
	m_observerList.removeOne(observer);
}


void SubjectA::notify()
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			m_observerList[i]->update(m_info1);
		else if (i == 1)
			m_observerList[i]->update(m_info2);
		else if (i == 2)
			m_observerList[i]->update(m_info3);
	}
}
