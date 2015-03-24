/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/**Implementation for clock based weekend decision interface:
   Responsibilities:
                        
	 1) Decide whether current time is weekend or not
*/

#ifndef __CLOCKDECISIONSTRATEGY_H
#define __CLOCKDECISIONSTRATEGY_H

#include "WeekendDecisionStrategy.h"

class ClockBasedDecisionStrategy : public WeekendDecisionStrategyInterface {
public:
	/// \return true if current day is on a weekend
	bool isWeekend();
};

#endif
