// main test module?

#include <cppunit/ui/text/TestRunner.h>
#include "TestPayStation.h"
#include "TestReceipt.h"
#include "TestProgressiveRatePS.h"
#include "TestProgressiveRateStrategy.h"
#include "TestIntegration.h"

int main() {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestPayStation::suite());
	runner.addTest(TestReceipt::suite());
	runner.addTest(TestProgressiveRatePS::suite());
	runner.addTest(TestProgressiveRateStrategy::suite());
	runner.addTest(TestIntegration::suite());
	runner.run();
	return 0;
}
