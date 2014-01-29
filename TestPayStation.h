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
	CPPUNIT_TEST(test25And10CentsAre14Min);
	CPPUNIT_TEST(testBuy);
	CPPUNIT_TEST(testBuy100Cents);
	CPPUNIT_TEST(shouldClearAfterBuy);
	CPPUNIT_TEST(shouldClearAfterCancel);
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

	/// Should display 10 min for 25 cents
	void test25CentsIs10Min() {
		ps->addPayment(25);
		CPPUNIT_ASSERT(25/5 * 2 == ps->readDisplay());
	}

	/// Should throw exception IllegalCoinException on illegal coin value
	void testEnterIllegalCoin() {
		ps->addPayment(17);
	}

	/// Should display 14 min for 10+25 cents
	void test25And10CentsAre14Min() {
		ps->addPayment(10);
		ps->addPayment(25);
		CPPUNIT_ASSERT((25+10)/5 * 2 == ps->readDisplay());
	}

	/// Should return a correct Receipt object for appropriate amount of time
	void testBuy() {
		ps->addPayment(5);
		ps->addPayment(10);
		ps->addPayment(25);
		Receipt receipt = ps->buy();
		// we have a valid receipt object returned
		CPPUNIT_ASSERT(receipt != NULL);
		// appropriate amount in receipt
		CPPUNIT_ASSERT((5+10+25)/5 * 2 == receipt->value());
		delete receipt;
	}

	/// should return correct Receipt for 100 cents
	void testBuy100Cents() {
		ps->addPayment(25);
		ps->addPayment(25);
		ps->addPayment(25);
		ps->addPayment(10);
		ps->addPayment(10);
		ps->addPayment(5);
		Receipt receipt = ps->buy();
		// we have a valid receipt object returned
		CPPUNIT_ASSERT(receipt != NULL);
		// appropriate amount in receipt
		CPPUNIT_ASSERT((3*25 + 2*10 + 5)/5 * 2 == receipt->value());
		delete receipt;
	}

	/// should clear display after buy
	void shouldClearAfterBuy() {
		ps->addPayment(25);
		delete ps->buy();  // don't use result now
		CPPUNIT_ASSERT(ps->readDisplay() == 0);
		ps->addPayment(10);
		ps->addPayment(25);
		// display correct result
		CPPUNIT_ASSERT((10+25)/5*2 == ps->readDisplay());
		// buy correct receipt again to see if correct after another buy
		Receipt receipt = ps->buy();
		CPPUNIT_ASSERT((10+25)/5*2 == receipt->value());
		// display should be reset
		CPPUNIT_ASSERT(0 == ps->readDisplay());
	}

	/// should clear after cancel
	void shouldClearAfterCancel() {
		ps->addPayment(10);
		ps->cancel();
		CPPUNIT_ASSERT(ps->readDisplay() == 0);
		ps->addPayment(25);
		// insert after cancel should work
		CPPUNIT_ASSERT(25/5*2 == ps->readDisplay());
	}
};

#endif
