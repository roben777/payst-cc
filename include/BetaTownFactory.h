/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** The pay station factory interface implementation for Alphatown

   Responsibilities:
                        
   1) Create RateStrategy object
   2) Create Receipt object
*/

#ifndef __BETATOWNFACTORY_H
#define __BETATOWNFACTORY_H

#include "PayStationFactory.h"
#include "ProgressiveRateStrategy.h"
#include "StandardReceipt.h"


/// class implementing the PayStationFactory interface; configures the
/// PayStationImpl with One2OneRateStrategy and StandardReceipt
class BetaTownFactory : public PayStationFactoryInterface {
public:
	RateStrategy createRateStrategy() {
		return new ProgressiveRateStrategy;
	}

	Receipt createReceipt(int parkingTime) {
		return new StandardReceipt(parkingTime, true);
	}

	DisplayStrategy createDisplayStrategy() {
		return new ValueDisplayStrategy;
	}
};


#endif
