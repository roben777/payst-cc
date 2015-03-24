/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

/** Implementation for RateStrategy interface that uses two functions
   depending on the system clock 
   Responsibilities:
                        
	 1) Provide an actual implementation for calculateTime function.
*/

#ifndef __ALTERNATINGRATESTRATEGY_H
#define __ALTERNATINGRATESTRATEGY_H

#include "RateStrategy.h"
#include "WeekendDecisionStrategy.h"

class AlternatingRateStrategy : public RateStrategyInterface {
private:
	RateStrategy weekendStrategy, weekdayStrategy, currentState;

	/// delegate object that tests if the current day falls on a weekend
	WeekendDecisionStrategy weekendDecision;
public:
	/// implementation for calculateTime function that implements
	/// Alphatown's linear strategy
	int calculateTime(int amount);

	/// constructor accepting the two strategies to alternate
	/// \param [in] weekend the weekend rate strategy to be used
	/// \param [in] weekday the weekday strategy to be used.
	/// \param [in] weStrategy the weekend decision strategy to use
	/// Note:
	/// the strategies are used alternatively depending on the day of
	/// the week for current time.
	AlternatingRateStrategy(RateStrategy weekend, RateStrategy weekday,
		WeekendDecisionStrategy weStrategy);

	/// destructor; remember to free the strategy objects
	~AlternatingRateStrategy();
};

#endif
