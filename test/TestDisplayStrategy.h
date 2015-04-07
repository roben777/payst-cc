/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// Testcases for the Receipt interface implementation

#ifndef __TESTDISPLAYSTRATEGY_H
#define __TESTDISPLAYSTRATEGY_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "TimeDisplayStrategy.h"
#include <ctime>

class TestDisplayStrategy : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestDisplayStrategy);
	CPPUNIT_TEST(test10MinDisplay);
	CPPUNIT_TEST_SUITE_END();

private:
	DisplayStrategy ds;
	
public:
	void setUp() {
		ds = new TimeDisplayStrategy;
	}

	void tearDown() {
		delete ds;
	}

	/// test if 10 minutes of parking time are correctly displayed as
	/// crt time + 10 min
	/// This test case is a bit tricky. I have several choices: write a
	/// stub for current time function, or I can mimic the
	/// production code here in which case one can wonder about the
	/// effectiveness of the test code. I choose the later option even
	/// though it is not the safest, because I will compute the test
	/// case time and the calculateOutput() time by 2 different methods.
	void test10MinDisplay() {
		struct tm *timeval;
		time_t tt;
		tt = time( NULL );
		tt += 10*60;  // 10 min in future. Assumes time() returns seconds
		timeval = localtime( &tt );
		CPPUNIT_ASSERT((timeval->tm_min +
										timeval->tm_hour * 100) == 
									 ds->calculateOutput(10));
	}
};

#endif
