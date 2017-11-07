#pragma once
#include "demo.h"
class IOA
{
public:
	virtual ~IOA(){}

	virtual void onAEvent(AEvent* event){}
	virtual void onBEvent(BEvent* event){}
};