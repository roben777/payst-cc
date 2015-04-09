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
#include "ValidCoinStrategy.h"

class PayStationImpl : public PayStationInterface {
private:
	int insertedSoFar;
	int timeBoughtSoFar;

	RateStrategy rateStrategy; ///< the strategy for rate calculation
	ValidCoin coinCheck; /// coin system

	/// clears the amount inserted so far and time bought
	void reset();
public:
	/// default constructor
	PayStationImpl();

	/// constructor
	/// \param [in] rs the rate strategy object to be used by the pay station.
	PayStationImpl(RateStrategy rs);
	
  void addPayment( int coinValue )
		throw (IllegalCoinException);
  
  int readDisplay();
  
  Receipt buy();

  void cancel();

	virtual ~PayStationImpl();
};

#endif
