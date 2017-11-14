#include "Eventbus.h"

size_t BaseEvent::getNextType()
{
	static size_t type_count = 0;
	return type_count++;
}

