#include "CurrentCharging.h"

CCurrentReport:: CCurrentReport(vector<int>& samples)
{
     sortedSamples = sortPeriodicCharingCurrentSamples(samples);
}

CCurrentReport::~CCurrentReport()
{

}

vector<int> CCurrentReport::sortPeriodicCharingCurrentSamples(vector<int>& samples)
{
    sort(samples.begin(), samples.end());
    return samples;
}

void CCurrentSet::initCurrentSet(int currentSampleData)
{
    lowval = currentSampleData;
    highval = currentSampleData;
    num = 1;
}

void CCurrentReport::generateContinuesCurrentRange()
{
    CCurrentSet set;
    set.initCurrentSet(sortedSamples[0]);
    for (int iter = 1; iter < sortedSamples.size(); ++iter)
    {
        if (sortedSamples[iter] - sortedSamples[iter - 1] < 2)
        {
             set.highval = sortedSamples[iter];
             set.num += 1;   
        }
        else
        {
            CurrentSetSamples.push_back(set);
            set.initCurrentSet(sortedSamples[iter]);
        }
    }
    CurrentSetSamples.push_back(set);
}

void CCurrentReport::consoleReport()
{
    cout << "Range, Readings" << endl;
    for (auto v : CurrentSetSamples)
    {
        cout << v.lowval << "-" << v.highval << ", " << v.num << endl;  
    }
}

bool CCurrentReport::validateRangeandReadings(int x, int y, int count)
{
    bool ret = false;

    for (auto v : CurrentSetSamples)
    {
        if ((v.lowval == x) && (v.highval) && (v.num == count))
        {
            ret = true;
            break;
        }
    }

    return ret;
}