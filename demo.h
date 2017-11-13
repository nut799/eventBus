#pragma once
#include "Eventbus.h"
#include <iostream>
class AEvent :public EV<AEvent>
{
 
};

class BEvent :public EV<BEvent>
{
 
};

/**/
class OA  
{
public:
	void onAEvent(AEvent* event)
	{
		std::cout << (" OA catchEvent onAEvent") << std::endl;
	}
	void onBEvent(BEvent* event)
	{
		std::cout << (" OA catchEvent onBEvent") << std::endl;
	}
};
 
class OB  {
public:
	void onAEvent(AEvent* event)
	{
		std::cout << (" OB catchEvent onAEvent") << std::endl;
	}
	void onBEvent(BEvent* event)
	{
		std::cout << (" OB catchEvent onBEvent") << std::endl;
	}
};
 
void demo()
{
	//EventBus bus;
	 
	OA a;
	OB b;
//	OC c;
 
	EventBus::getInstance()->subscribe<AEvent>(&a, &OA::onAEvent);
	EventBus::getInstance()->subscribe<BEvent>(&a, &OA::onBEvent);
	EventBus::getInstance()->subscribe<AEvent>(&b, &OB::onAEvent);
	EventBus::getInstance()->subscribe<BEvent>(&b, &OB::onBEvent);

	AEvent aevent;
	EventBus::getInstance()->emit(&aevent);

	BEvent bevent;
	EventBus::getInstance()->emit(&bevent);

	EventBus::getInstance()->unSubcribe<AEvent>(&a, &OA::onAEvent);
	EventBus::getInstance()->emit(&aevent);

}