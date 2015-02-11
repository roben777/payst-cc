/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// \file Testcases for the Pay Station System with Progressive Rate

#ifndef __TESTPROGRESSIVERATEPS_H
#define __TESTPROGRESSIVERATEPS_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PayStationImpl.h"
#include "ProgressiveRateStrategy.h"

/// Test fixture for PayStation class configured with ProgressiveRateStrategy
class TestProgressiveRatePS : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestProgressiveRatePS);
	CPPUNIT_TEST(test1HourCosts150Cents);
	CPPUNIT_TEST(test2HoursCost350Cents);
	CPPUNIT_TEST(test3HoursCost650Cents);
	CPPUNIT_TEST_SUITE_END();


private:
	PayStation ps; ///< the PayStation object

	/// helper function to insert 1 dollar payment; declared private
	void add1Dollar() {
		ps->addPayment(25);  ps->addPayment(25);
		ps->addPayment(25);  ps->addPayment(25);
	};

public:
	void setUp() {
		ps = new PayStationImpl(new ProgressiveRateStrategy);
	};


	void tearDown() {
		delete ps;
	};

	/// testcase for buying 1 hour
	void test1HourCosts150Cents() {
		add1Dollar();
		ps->addPayment(25); ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == 60 /*min*/);
	};

	/// testcase 2 h = 1.5 + 2 dollars
	void test2HoursCost350Cents() {
		add1Dollar();  add1Dollar();
		add1Dollar();
		ps->addPayment(25); ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
	};

	/// testcase 3 h = 1.5 + 2 + 3 dollars
	void test3HoursCost650Cents()  {
		add1Dollar();  add1Dollar();
		add1Dollar();  add1Dollar();
		add1Dollar();  add1Dollar();
		ps->addPayment(25); ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == 180 /*min*/);
	};
};

#endif
