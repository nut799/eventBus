#pragma once
#include "eventbus.h"
#include <iostream>
class AEvent :public Event<AEvent>
{
 
};

class BEvent :public Event<BEvent>
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
/* 
class OB : public Observer
{
public:
	void catchEvent(BaseEvent* e)
	{
		if (e->getMyType() == Event_A)
		{
			std::cout << (" OB catchEvent Event_A") << std::endl;
		}
		else if (e->getMyType() == Event_B)
		{
			std::cout << (" OB catchEvent Event_B") << std::endl;
		}
	}
};
 
class OC : public Observer
{
public:
	void catchEvent(BaseEvent* e)
	{
		if (e->getMyType() == Event_A)
		{
			std::cout << (" OC catchEvent Event_A") << std::endl;
		}
		else if (e->getMyType() == Event_B)
		{
			std::cout << (" OC catchEvent Event_B") << std::endl;
		}
	}
};
*/
void test()
{
	
	EventBus bus;
	 
	OA a;
 
	bus.subscribe<AEvent>(&a, &OA::onAEvent);
	bus.subscribe<BEvent>(&a, &OA::onBEvent);
	//sys.addObserver(&a, Event_A);
	//sys.addObserver(&a, Event_B);

	//sys.addObserver(&b, Event_A);
	//sys.addObserver(&c, Event_A);

	AEvent aevent;
 
 
	bus.emit<AEvent>(&aevent);

	 
	bus.unSubcribe<AEvent>(&a, &OA::onAEvent);
	bus.emit<AEvent>(&aevent);

 
	 
}