/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/// \file Testcases for integration

#ifndef __TESTINTEGRATION_H
#define __TESTINTEGRATION_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PayStationImpl.h"
#include "AlphaTownFactory.h"
#include "BetaTownFactory.h"
#include "GammaTownFactory.h"

#include <sstream>

/// Test fixture for ProgressiveRateStrategy
class TestIntegration : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestIntegration);
	CPPUNIT_TEST(testPSAlpha2h300cStandard);
	CPPUNIT_TEST(testPSBeta2h350cBar);
	CPPUNIT_TEST(testPSGammaWeekday2h300c);
	CPPUNIT_TEST_SUITE_END();

private:
	PayStation ps;
	
	void add1Dollar()  {
		ps->addPayment(25);  ps->addPayment(25);
		ps->addPayment(25);  ps->addPayment(25); 
	};


	/// helper function to count the number of lines in a Receipt object.
	/// \param [in] r the receipt object. Must be not NULL
	/// \return the number of lines printed by receipt->print()
	int nrLinesInReceipt(Receipt r) {
		std::ostringstream sstr;
		r->print(sstr);
		std::string s = sstr.str();
		int nLines = 0;  // the count of lines in s
		std::size_t lastNLOffset = -1;  // offset of the most recent newline
		do {
			lastNLOffset = s.find('\n',lastNLOffset+1);
			nLines++;
		}
		while (lastNLOffset != std::string::npos);
		return nLines;
	}
	

public:
	// integrate test PS and Linear strategy
	void testPSAlpha2h300cStandard()  {
		ps = new PayStationImpl(new AlphaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
		Receipt receipt = ps->buy();
		CPPUNIT_ASSERT(receipt != NULL);
		CPPUNIT_ASSERT(nrLinesInReceipt(receipt) == 3);
		
		delete receipt;
		delete ps;
	};

		// integrate test PS and Beta Factory and test for bar receipt
	void testPSBeta2h350cBar()  {
		ps = new PayStationImpl(new BetaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		ps->addPayment(25);  ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
		Receipt receipt = ps->buy();
		CPPUNIT_ASSERT(receipt != NULL);
		CPPUNIT_ASSERT(nrLinesInReceipt(receipt) == 4);
		
		delete receipt;
		delete ps;
	};

	// PS and Gammatown factory. Test that alternating strategy works
	// for weekday (linear). This is the real clock based weekend
	// decision, and  so this test will fail on weekends;
	// Also test that the standard receipt is returned
	void testPSGammaWeekday2h300c() {
		ps = new PayStationImpl(new GammaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		CPPUNIT_ASSERT(ps->readDisplay() == 120 /* fails on weekends */);

		// I want to test the receipts. Instead of making a separate test
		// case for receipts, I add the test code here since readDisplay
		// is too simple to mess up my test case
		Receipt receipt = ps->buy();
		CPPUNIT_ASSERT(receipt != NULL);
		CPPUNIT_ASSERT(nrLinesInReceipt(receipt) == 3);
		
		delete receipt;
		delete ps;		
	}

};

#endif
