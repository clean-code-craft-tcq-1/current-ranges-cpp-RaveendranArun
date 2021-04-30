#ifndef CURRENT_CHARGING_H_
#define CURRENT_CHARGING_H_

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class CCurrentReport;

class CCurrentSet
{
private:
    int lowval;
    int highval;
    int num;
public:
    void initCurrentSet(int val);
    friend class CCurrentReport;
};

class CCurrentReport
{
private:
    vector<CCurrentSet> CurrentSetSamples;
    vector<int> sortedSamples;
public:
    CCurrentReport(vector<int>& samples);
    vector<int> sortPeriodicCharingCurrentSamples(vector<int>& samples);
    void generateContinuesCurrentRange(vector<int>& samples);
    void consoleReport();
    bool validateRangeandReadings(int x, int y, int z);
    ~CCurrentReport();
};

#endif