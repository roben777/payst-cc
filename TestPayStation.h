/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// Testcases for the Pay Station System

#ifndef __TESTPAYSTATION_H
#define __TESTPAYSTATION_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PayStationImpl.h"

class TestPayStation : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPayStation);
	CPPUNIT_TEST(test5CentsIs2Min);
	CPPUNIT_TEST(test25CentsIs10Min);
	CPPUNIT_TEST_EXCEPTION(testEnterIllegalCoin, IllegalCoinException);
	CPPUNIT_TEST_SUITE_END();
	
private:
	PayStation ps;
public:
	void setUp() {
		ps = new PayStationImpl;
	}

	void tearDown() {
		delete ps;
	}

	/// the test function. Should display 2 minutes for 5 cents
	void test5CentsIs2Min() {
		ps->addPayment(5);
		CPPUNIT_ASSERT(5/5 * 2 == ps->readDisplay());
	};

	// Should display 10 min for 25 cents
	void test25CentsIs10Min() {
		ps->addPayment(25);
		CPPUNIT_ASSERT(25/5 * 2 == ps->readDisplay());
	}

	// Should throw exception IllegalCoinException on illegal coin value
	void testEnterIllegalCoin() {
		ps->addPayment(17);
	}
};

#endif
