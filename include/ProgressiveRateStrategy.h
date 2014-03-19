/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Implementation for RateStrategy interface that uses a piecewise
   linear function 
   Responsibilities:
                        
	 1) Provide an actual implementation for calculateTime function.
*/

#ifndef __PROGRESSIVERATESTRATEGY_H
#define __PROGRESSIVERATESTRATEGY_H

#include "RateStrategy.h"

class ProgressiveRateStrategy : public RateStrategyInterface {
public:
	/// implementation for calculateTime function that implements
	/// Alphatown's linear strategy
	int calculateTime(int amount);
};

#endif
