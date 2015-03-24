/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// \file Testcases for the Al;ternating Rate Strategy only

#ifndef __TESTALTERNATINGRATESTRATEGY_H
#define __TESTALTERNATINGRATESTRATEGY_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "AlternatingRateStrategy.h"
#include "FixedDecisionStrategy.h"

/// Test fixture for ProgressiveRateStrategy
class TestAlternatingRateStrategy : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestAlternatingRateStrategy);
	CPPUNIT_TEST(testWD300CentsAre120Min);
	CPPUNIT_TEST_SUITE_END();
private:
	RateStrategy rsWDay, rsWEnd;

public:
	void setUp()  {
		rsWDay = new AlternatingRateStrategy(new ProgressiveRateStrategy,
																				 new LinearRateStrategy,
																				 new FixedDecisionStrategy(false));
		rsWEnd = new AlternatingRateStrategy(new ProgressiveRateStrategy,
																				 new LinearRateStrategy,
																				 new FixedDecisionStrategy(true));
	};

	void tearDown()  {
		delete rsWDay;  delete rsWEnd;
	};

	void testWD300CentsAre120Min()  {
		CPPUNIT_ASSERT(rsWDay->calculateTime(300/*cents*/) == 120 /*min*/);
	}
};

#endif
