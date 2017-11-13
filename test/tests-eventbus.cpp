
#include "catch.hpp"
#include "Eventbus.h"
#include "mocks.hpp"

SCENARIO("checking eventbus", "[eventbus]") {
	GIVEN("OA with register AEvent") {
		EventBus bus;
 
		WHEN("when subscribe AEvent"){
			mockOA mockOA;
			bus.subscribe<AEvent>(&mockOA, &mockOA::onAEvent);

			THEN("the OA onAEvent() will be called") {
				EXPECT_CALL(mockOA, onAEvent(testing::_)).Times(::testing::AtLeast(1));
				AEvent aevent;
				bus.emit(&aevent);
			}
			bus.unSubcribe<AEvent>(&mockOA, &mockOA::onAEvent);
			SUCCEED();
		}
		 
		WHEN("when unSubcribe AEvent"){
			mockOA mockOA;
			bus.subscribe<AEvent>(&mockOA, &mockOA::onAEvent);
			bus.unSubcribe<AEvent>(&mockOA, &mockOA::onAEvent);
			THEN("the OA onAEvent() will not be called") {
				EXPECT_CALL(mockOA, onAEvent(testing::_)).Times(0);
				AEvent aevent;
				bus.emit(&aevent);
			}
			 
			SUCCEED();
		}
	 
	}
}
 
