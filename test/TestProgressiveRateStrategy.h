/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// \file Testcases for the Progressive Rate Strategy only

#ifndef __TESTPROGRESSIVERATESTRATEGY_H
#define __TESTPROGRESSIVERATESTRATEGY_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ProgressiveRateStrategy.h"

/// Test fixture for ProgressiveRateStrategy
class TestProgressiveRateStrategy : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestProgressiveRateStrategy);
	CPPUNIT_TEST(test3HoursCost650Cents);
	CPPUNIT_TEST_SUITE_END();
private:
	RateStrategy rs;

public:
	void setUp()  {
		rs = new ProgressiveRateStrategy;
	};

	void tearDown()  {
		delete rs;
	};

	void test3HoursCost650Cents()  {
		CPPUNIT_ASSERT(rs->calculateTime(650/*cents*/) == 180 /*min*/);
	}
};

#endif
