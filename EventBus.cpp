#include "Eventbus.h"

size_t BaseEvent::getNextType()
{
	static size_t type_count = 0;
	return type_count++;
}

EventBus* EventBus::Instance = nullptr;//static member define.
EventBus* EventBus::getInstance()
{
	if (Instance == nullptr)
	{
		Instance = new EventBus();
	}
	return Instance;
}

void EventBus::delInstance()
{
	if (Instance != nullptr)
	{
		delete Instance;
		Instance = nullptr;
	}
}