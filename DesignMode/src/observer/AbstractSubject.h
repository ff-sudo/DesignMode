/*
Ŀ�����Ŀ���������ڶ�۲��ߵĶ���
�������º��Զ�֪ͨ���ܶ��ĵĶ���
*/

#include <iostream>


class AbstractObserver;
class AbstractSubject
{
public:
	//��ӹ۲���
	virtual void attach(AbstractObserver* observer) = 0;
	
	//ɾ���۲���
	virtual void detach(AbstractObserver* observer) = 0;

	//֪ͨ���й۲���
	virtual void notify() = 0;
};