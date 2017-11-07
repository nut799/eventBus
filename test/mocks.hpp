#ifndef TEST_MOCKS_HPP_
#define TEST_MOCKS_HPP_

#include "eventbus.h"
#include "demo.h"
#include "interfaces.h"
#include "gmock/gmock.h"
class mockOA : public IOA {
public:
	virtual ~mockOA() {
	}
 
	MOCK_METHOD1(onAEvent, void(AEvent* event));
	MOCK_METHOD1(onBEvent, void(BEvent* event));
};

 
#endif /* TEST_MOCKS_HPP_ */

