/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "PayStationImpl.h"

void PayStationImpl::addPayment( int coinValue )
	throw (IllegalCoinException){
	switch (coinValue) {
		case 5: break;
		case 10: break;
		case 25: break;
		default:
			throw IllegalCoinException("Invalid coin: " + coinValue);
	}
	insertedSoFar = coinValue;
}
  
int PayStationImpl::readDisplay() {
	return insertedSoFar / 5 * 2;
}
  
Receipt PayStationImpl::buy() {
	return NULL;
}

void PayStationImpl::cancel() {
}

PayStationImpl::~PayStationImpl() {
}
