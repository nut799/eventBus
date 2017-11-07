// test.cpp : Defines the entry point for the console application.
//


//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
 


#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "gmock/gmock.h"

#include "gmock_catch_interceptor.hpp"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
	//listeners.Append(new cokeley::gmock_catch_interceptor());
	listeners.Append(new gmock_catch_interceptor());
	delete listeners.Release(listeners.default_result_printer());

	return Catch::Session().run(argc, argv);
}