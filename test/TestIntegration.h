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
	CPPUNIT_TEST(testPSLinear2h300c);
	CPPUNIT_TEST(testPSProgressive2h350c);
	CPPUNIT_TEST(testPSGammaWeekday2h300c);
	CPPUNIT_TEST_SUITE_END();

private:
	PayStation ps;
	
	void add1Dollar()  {
		ps->addPayment(25);  ps->addPayment(25);
		ps->addPayment(25);  ps->addPayment(25); 
	};


public:
	// integrate test PS and Linear strategy
	void testPSLinear2h300c()  {
		ps = new PayStationImpl(new AlphaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
		delete ps;
	};

		// integrate test PS and Linear strategy
	void testPSProgressive2h350c()  {
		ps = new PayStationImpl(new BetaTownFactory);
		add1Dollar();  add1Dollar();  add1Dollar();
		ps->addPayment(25);  ps->addPayment(25);
		CPPUNIT_ASSERT(ps->readDisplay() == 120);
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
		std::ostringstream sstr;
		receipt->print(sstr);
		std::string s = sstr.str();  // get the output as string
		std::size_t line1 = s.find('\n');
		std::size_t line2 = s.find('\n',line1+1);
		std::size_t lineCollon = s.find(':', line2+1);
		CPPUNIT_ASSERT(s.substr(0, line1) == "PARKING RECEIPT");
		CPPUNIT_ASSERT(s.substr(line1+1, line2-line1-1) == "Value: 120 min.");
		CPPUNIT_ASSERT(s.substr(line2+1, lineCollon-line2-1) == "Car parked at");
		CPPUNIT_ASSERT(s[lineCollon+4] == ':');

		delete receipt;
		delete ps;		
	}

};

#endif
