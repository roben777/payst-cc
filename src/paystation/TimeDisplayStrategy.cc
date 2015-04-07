#include "TimeDisplayStrategy.h"
#include <ctime>

#define MINPERH 60
#define HPERDAY 24

int TimeDisplayStrategy::calculateOutput(int timeBought) {
	struct tm *timeval;
	time_t tt;
	tt = time( NULL );
	timeval = localtime( &tt );
	return ((timeval->tm_min + timeBought) % MINPERH +
					100 * (( timeval->tm_hour +
									 (timeval->tm_min + timeBought) / MINPERH ) % HPERDAY));
}
