/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// Testcases for the Pay Station System

#ifndef __TESTPAYSTATIONUNIT_H
#define __TESTPAYSTATIONUNIT_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PayStationImpl.h"
#include "One2OneRateStrategy.h"

class TestPayStationUnit : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPayStationUnit);
	CPPUNIT_TEST(testShouldAcceptLegalCoins);
	CPPUNIT_TEST_SUITE_END();
	
private:
	PayStation ps;
	
public:
	void setUp() {
		ps = new PayStationImpl (new One2OneRateStrategy);
	}

	void tearDown() {
		delete ps;
	}

	void testShouldAcceptLegalCoins()  {
		ps->addPayment(5);
		ps->addPayment(10);
		ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == (5+10+25));
	}

};

#endif
