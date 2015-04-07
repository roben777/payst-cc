// main test module?

#include <cppunit/ui/text/TestRunner.h>
#include "TestReceipt.h"
#include "TestProgressiveRateStrategy.h"
#include "TestIntegration.h"
#include "TestPayStationUnit.h"
#include "TestAlternatingRateStrategy.h"

int main() {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestReceipt::suite());
	runner.addTest(TestProgressiveRateStrategy::suite());
	runner.addTest(TestIntegration::suite());
	runner.addTest(TestPayStationUnit::suite());
	runner.addTest(TestAlternatingRateStrategy::suite());
	runner.run();
	return 0;
}
