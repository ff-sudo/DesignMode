/*
�۲��ߣ������Ľ��չ۲�������Ϣ
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