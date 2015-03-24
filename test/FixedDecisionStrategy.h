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

#ifndef __FIXEDDECISIONSTRATEGY_H
#define __FIXEDDECISIONSTRATEGY_H

#include "WeekendDecisionStrategy.h"

class FixedDecisionStrategy : public WeekendDecisionStrategyInterface {
private:
	bool weekend; // true if should return weekend
public:
	/// \return true if current day is on a weekend
	bool isWeekend() {
		return weekend;
	}

	/// constructor
	/// \param [in] theWeekend true if the object should always return
	/// weekend state, false if it should return weekday state 
	FixedDecisionStrategy(bool theWeekend) {
		weekend = theWeekend;
	}
};

#endif
