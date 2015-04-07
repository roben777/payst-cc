/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** The pay station factory interface implementation

   Responsibilities:
                        
   1) Create RateStrategy object
   2) Create Receipt object
*/

#ifndef __TESTTOWNFACTORY_H
#define __TESTTOWNFACTORY_H

#include "PayStationFactory.h"
#include "One2OneRateStrategy.h"
#include "StandardReceipt.h"
#include "ValueDisplayStrategy.h"
#include <cstddef>


/// class implementing the PayStationFactory interface; configures the
/// PayStationImpl with One2OneRateStrategy and StandardReceipt
class TestTownFactory : public PayStationFactoryInterface {
public:
	RateStrategy createRateStrategy() {
		return new One2OneRateStrategy;
	}

	Receipt createReceipt(int parkingTime) {
		return new StandardReceipt(parkingTime);
	}
	
	DisplayStrategy createDisplayStrategy() {
		return new ValueDisplayStrategy;
	}
};


#endif
