// test.cpp : Defines the entry point for the console application.
//


//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file


#include "gmock/gmock.h"



int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}