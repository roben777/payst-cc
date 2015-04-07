/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** The pay station factory interface implementation for Gammatown

   Responsibilities:
                        
   1) Create RateStrategy object
   2) Create Receipt object
*/

#ifndef __GAMMATOWNFACTORY_H
#define __GAMMATOWNFACTORY_H

#include "PayStationFactory.h"
#include "LinearRateStrategy.h"
#include "ProgressiveRateStrategy.h"
#include "AlternatingRateStrategy.h"
#include "ClockBasedDecisionStrategy.h"
#include "StandardReceipt.h"


/// class implementing the PayStationFactory interface; configures the
/// PayStationImpl with One2OneRateStrategy and StandardReceipt
class GammaTownFactory : public PayStationFactoryInterface {
public:
	RateStrategy createRateStrategy() {
		return new AlternatingRateStrategy(new ProgressiveRateStrategy,
																			 new LinearRateStrategy,
																			 new ClockBasedDecisionStrategy);
	}

	Receipt createReceipt(int parkingTime) {
		return new StandardReceipt(parkingTime);
	}
};


#endif
