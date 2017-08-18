#pragma once
#include "eventManager.h"
#include <iostream>
class AEvent : public BaseEvent
{
public:
	EventType getMyType()
	{
		return Event_A;
	}
};

class BEvent : public BaseEvent
{
public:
	EventType getMyType()
	{
		return Event_B;
	}
};

class OA : public Observer
{
public:
	void catchEvent(BaseEvent* e)
	{
		if (e->getMyType() == Event_A)
		{
			std::cout << (" OA catchEvent Event_A") << std::endl;
		}
		else if (e->getMyType() == Event_B)
		{
			std::cout << (" OA catchEvent Event_B") << std::endl;
		}
	}
};

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

void test()
{
	Observed sys;

	OA a;
	OB b;
	OC c;

	sys.addObserver(&a, Event_A);
	sys.addObserver(&a, Event_B);

	sys.addObserver(&b, Event_A);
	sys.addObserver(&c, Event_A);

	AEvent aevent;
	std::cout << ("1 sendEvent Event_A") << std::endl;
 
	sys.sendEvent(&aevent);

	std::cout << ("2 OA removeObserver Event_A") << std::endl;
	sys.removeObserver(&a, Event_A);
	AEvent aevent1;
	std::cout << ("  sendEvent Event_A") << std::endl;
	 
	sys.sendEvent(&aevent1);
}