#include "Eventbus.h"
#include "mocks.hpp"


class EventBus_Test : public testing::Test {
	virtual void SetUp(){
 
	}

	virtual void TearDown(){
 
	}
protected:
	mockOA mockObserver;//call back 
	EventBus bus;
};

TEST_F(EventBus_Test, Subscribe_Triger_callback){
	bus.subscribe<AEvent>(&mockObserver, &mockOA::onAEvent);
	EXPECT_CALL(mockObserver, onAEvent(testing::_)).Times(::testing::AtLeast(1));

	AEvent aevent;
	bus.emit(&aevent);
	bus.unSubcribe<AEvent>(&mockObserver, &mockOA::onAEvent);
}

TEST_F(EventBus_Test, Unsubscribe_Should_Not_Triger_callback){
	bus.subscribe<AEvent>(&mockObserver, &mockOA::onAEvent);
	bus.unSubcribe<AEvent>(&mockObserver, &mockOA::onAEvent);
	EXPECT_CALL(mockObserver, onAEvent(testing::_)).Times(0);

	AEvent aevent;
	bus.emit(&aevent);
}
