/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "PayStationImpl.h"
#include "ReceiptImpl.h"
//#include "LinearRateStrategy.h"

void PayStationImpl::addPayment( int coinValue )
	throw (IllegalCoinException){
	switch (coinValue) {
		case 5: break;
		case 10: break;
		case 25: break;
		default:
			throw IllegalCoinException("Invalid coin: " + coinValue);
	}
	insertedSoFar += coinValue;
	timeBoughtSoFar = rateStrategy->calculateTime(insertedSoFar);
}
  
int PayStationImpl::readDisplay() {
	return timeBoughtSoFar;
}
  
Receipt PayStationImpl::buy() {
	Receipt r =  new ReceiptImpl(timeBoughtSoFar);
	reset();
	return r;
}

void PayStationImpl::cancel() {
	reset();
}

PayStationImpl::~PayStationImpl() {
	// before I start Iteration 5, I realize that I have a memory leak
	// (another example of something hard to test automatically; use
	// valgrind instead) 
	// RateStrategy is a pointer. We make a convention: whenever we pass
	// the pointer to a function, the function owns it and it is
	// responsible to free it. So we must not pass pointers to automatic
	// variables. The function must free it.
	// See std::auto_ptr for a safer way to do all of this
	delete rateStrategy;
}

// PayStationImpl::PayStationImpl() {
// 	reset();
// 	rateStrategy = new LinearRateStrategy; // the default strategy
// }

void PayStationImpl::reset() {
	insertedSoFar = timeBoughtSoFar = 0;
}

PayStationImpl::PayStationImpl(RateStrategy rs) {
	reset();
	rateStrategy = rs;  // rs is a pointer to allocated memory
}
