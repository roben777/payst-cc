/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Implementation for RateStrategy interface that uses a 1to1 function
   It is used as test stub for testing PayStationImpl
                        
	 1) Provides an implementation for calculateTime function.
*/

#ifndef __ONE2ONERATESTRATEGY_H
#define __ONE2ONERATESTRATEGY_H

#include "RateStrategy.h"

class One2OneRateStrategy : public RateStrategyInterface {
public:
	/// RateStrategy stub to unit test PayStationImpl
	int calculateTime(int amount) { return amount; };
};

#endif
