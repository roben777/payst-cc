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
#include "LinearRateStrategy.h"

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
}

PayStationImpl::PayStationImpl() {
	reset();
	rateStrategy = new LinearRateStrategy; // the default strategy
}

void PayStationImpl::reset() {
	insertedSoFar = timeBoughtSoFar = 0;
}

PayStationImpl::PayStationImpl(RateStrategy rs) {
	reset();
	rateStrategy = rs;  // rs is a pointer to allocated memory
}
