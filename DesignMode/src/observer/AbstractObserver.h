/*
观察者，被动的接收观察对象的消息
*/
#include <iostream>
#include <vector>
#include <queue>

class AbstractObserver
{
public:
	virtual void update() = 0;
	virtual void update(std::string info ) {};

};