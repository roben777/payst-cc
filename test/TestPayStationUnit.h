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
#include "TestTownFactory.h"

class TestPayStationUnit : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPayStationUnit);
	CPPUNIT_TEST(testShouldAcceptLegalCoins);
	CPPUNIT_TEST_EXCEPTION(testEnterIllegalCoin, IllegalCoinException);
	CPPUNIT_TEST(testBuy);
	CPPUNIT_TEST(testBuy100Cents);
	CPPUNIT_TEST(shouldClearAfterBuy);
	CPPUNIT_TEST(shouldClearAfterCancel);
	CPPUNIT_TEST_SUITE_END();
	
private:
	PayStation ps;
	
public:
	void setUp() {
		ps = new PayStationImpl (new TestTownFactory);
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

	/// Should throw exception IllegalCoinException on illegal coin value
	void testEnterIllegalCoin() {
		ps->addPayment(17);
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
		CPPUNIT_ASSERT((5+10+25) == receipt->value());
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
		CPPUNIT_ASSERT(100 == receipt->value());
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
		CPPUNIT_ASSERT((10+25) == ps->readDisplay());
		// buy correct receipt again to see if correct after another buy
		Receipt receipt = ps->buy();
		CPPUNIT_ASSERT((10+25) == receipt->value());
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
		CPPUNIT_ASSERT(25 == ps->readDisplay());
	}
};

#endif
