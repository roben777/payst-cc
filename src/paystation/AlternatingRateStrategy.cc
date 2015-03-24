/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "AlternatingRateStrategy.h"
#include <cstddef>

int AlternatingRateStrategy::calculateTime(int amount) {
	if (weekendDecision->isWeekend())
		currentState = weekendStrategy;
	else
		currentState = weekdayStrategy;
	return currentState->calculateTime(amount);
}


AlternatingRateStrategy::AlternatingRateStrategy
(RateStrategy weekend, RateStrategy weekday,
	WeekendDecisionStrategy weStrategy)  {
	weekendStrategy = weekend;
	weekdayStrategy = weekday;
	currentState = NULL;
	weekendDecision = weStrategy;
}


AlternatingRateStrategy::~AlternatingRateStrategy() {
	delete weekendStrategy;
	delete weekdayStrategy;
	delete weekendDecision;
}
