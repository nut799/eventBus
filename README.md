EventBus 
=====

#demo

```
#pragma once
#include <iostream>
#include "eventbus.h"
 

class AEvent :public Event<AEvent>
{
 
};

class BEvent :public Event<BEvent>
{
 
};

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
 
void test()
{
	
	EventBus bus;
	 
	OA a;
	OB b;
 
	bus.subscribe<AEvent>(&a, &OA::onAEvent);
	bus.subscribe<BEvent>(&a, &OA::onBEvent);
	bus.subscribe<AEvent>(&b, &OB::onAEvent);
	bus.subscribe<BEvent>(&b, &OB::onBEvent);

	AEvent aevent;
	bus.emit<AEvent>(&aevent);

	BEvent bevent;
	bus.emit<BEvent>(&bevent);

	bus.unSubcribe<AEvent>(&a, &OA::onAEvent);
	bus.emit<AEvent>(&aevent);
}
```

#UT
