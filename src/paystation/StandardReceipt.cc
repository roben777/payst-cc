/* Source code for textbook:
 Flexible Reliable Software, by Henrik B. Christensen
 CRC Press 2010 
 ***********************************
 Project developped in java by Henrik B. Christensen
 C++ port by Robert Benkoczi
 ***********************************
 */

#include "StandardReceipt.h"
#include <ctime>
#include <sstream>
#include <iomanip>

StandardReceipt::StandardReceipt(int amountOfTime, bool hasBar) {
	theValue = amountOfTime;
	printBar = hasBar;
}


int StandardReceipt::value() {
	return theValue;
}


void StandardReceipt::print(std::ostream& str)  {
	str << "PARKING RECEIPT" << std::endl;
	str << "Value: " << value() << " min." << std::endl;
	str << "Car parked at: " << currentTime();
	if (printBar) {
		str  << std::endl << "|||||||||||||||";
	}
}


std::string StandardReceipt::currentTime() {
	struct tm *timeval;
	time_t tt;
	tt = time( NULL );
	timeval = localtime( &tt );

	std::ostringstream sstr;
	sstr.fill('0');
	sstr << std::right << std::setw(2) << timeval->tm_hour << ':'
			 << std::setw(2) << timeval->tm_min;

	return sstr.str();
}
