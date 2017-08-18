#pragma once 
#include <vector>
#include <map>
#include <algorithm>
enum EventType
{
	Event_A,
	Event_B,
};

class BaseEvent
{
public:
	virtual EventType getMyType() = 0;
};

class Observer // for this example i'll suppose observer inherits this class
{
public:
	virtual void catchEvent(BaseEvent* e) = 0;
	virtual ~Observer(){}; // virtual base classes require this to work fine.
};

class Observed
{
	typedef std::vector<Observer*> ObserverList;
	typedef std::map< EventType, ObserverList > ObserversTable;
	ObserversTable m_observers; // we have observers for each event type

public:

	void addObserver(Observer* observer, EventType eType)
	{
		m_observers[eType].push_back(observer);
	} 

	void removeObserver(Observer* observer, EventType eType)
	{
		ObserverList& observers = m_observers[eType];

		for (ObserverList::iterator it = observers.begin(); it != observers.end();)
		{
			if (*it == observer)
			{
				it = observers.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	void sendEvent(BaseEvent* event)// here we send the event, it will be catched by observers
	{ 
		ObserverList& observers = m_observers[event->getMyType()];
		for (ObserverList::iterator it = observers.begin(); it != observers.end(); ++it)
		{
			Observer* observer = *it;
			observer->catchEvent(event);
		}

	}
};


 