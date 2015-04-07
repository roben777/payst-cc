/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Implementation of the pay station.

   Responsibilities:
                        
   1) Accept payment;
   2) Calculate parking time based on payment;
   3) Know earning, parking time bought;
   4) Issue receipts;
   5) Handle buy and cancel events.
*/

#ifndef __PAYSTATIONIMPL_H
#define __PAYSTATIONIMPL_H

#include "PayStation.h"
#include "RateStrategy.h"
#include "PayStationFactory.h"

class PayStationImpl : public PayStationInterface {
private:
	int insertedSoFar;
	int timeBoughtSoFar;

	RateStrategy rateStrategy; ///< the strategy for rate calculation
	PayStationFactory psFactory; ///< the factory object to create receipts

	/// clears the amount inserted so far and time bought
	void reset();
public:
	/// constructor
	/// \param [in] pf the factory object to be used by the pay station.
	PayStationImpl(PayStationFactory pf);
	
  void addPayment( int coinValue )
		throw (IllegalCoinException);
  
  int readDisplay();
  
  Receipt buy();

  void cancel();

	virtual ~PayStationImpl();
};

#endif
