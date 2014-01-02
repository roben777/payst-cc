// main test module?

#include "TestPayStation.h"

int main() {
	TestPayStation test("PayStationImpl test");
	test.test5CentsIs2Min();
	test.test25CentsIs10Min();
	return 0;
}
