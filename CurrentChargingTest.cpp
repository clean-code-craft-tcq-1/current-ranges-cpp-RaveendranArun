#include "CurrentCharging.h"
#include <cassert>

int main()
{
    vector<int> periodicSamples = {1, 3, 5, 3, 4, 2, 27, 29, 28, 30, 10, 11, 12, 53, 51, 52};
    CCurrentReport obj(periodicSamples);
    obj.generateContinuesCurrentRange();
    obj.consoleReport();
    assert(obj.validateRangeandReadings(1, 5, 6) == true);
    assert(obj.validateRangeandReadings(10, 12, 3) == true);
    assert(obj.validateRangeandReadings(27, 30, 4) == true);
    assert(obj.validateRangeandReadings(51, 53, 3) == true);
    assert(obj.validateRangeandReadings(50, 53, 3) == false);
    assert(obj.validateRangeandReadings(9, 8, 3) == false);
    assert(obj.validateRangeandReadings(20, 25, 3) == false);
    assert(obj.validateRangeandReadings(1, 5, 3) == false);

    return 0;
}