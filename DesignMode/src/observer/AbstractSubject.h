/*
目标对象，目标对象接收众多观察者的订阅
发布更新后，自动通知接受订阅的对象
*/

#include <iostream>


class AbstractObserver;
class AbstractSubject
{
public:
	//添加观察者
	virtual void attach(AbstractObserver* observer) = 0;
	
	//删除观察者
	virtual void detach(AbstractObserver* observer) = 0;

	//通知所有观察者
	virtual void notify() = 0;
};