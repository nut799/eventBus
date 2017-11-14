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
	EventBus bus;
	 
	OA a;
	OB b;
//	OC c;
 
	bus.subscribe<AEvent>(&a, &OA::onAEvent);
	bus.subscribe<BEvent>(&a, &OA::onBEvent);
	bus.subscribe<AEvent>(&b, &OB::onAEvent);
	bus.subscribe<BEvent>(&b, &OB::onBEvent);

	AEvent aevent;
	bus.emit(&aevent);

	BEvent bevent;
	bus.emit(&bevent);

	bus.unSubcribe<AEvent>(&a, &OA::onAEvent);
	bus.emit(&aevent);

}