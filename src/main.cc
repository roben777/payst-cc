// main test module?

#include <cppunit/ui/text/TestRunner.h>
#include "TestPayStation.h"
#include "TestReceipt.h"

int main() {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestPayStation::suite());
	runner.addTest(TestReceipt::suite());
	runner.run();
	return 0;
}
