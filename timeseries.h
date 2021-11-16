#ifndef ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H
#define ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class timeseries {
    // saving the names in a vector in their original order
    vector<string> names;
    //saving the data in a map, the keys are the names of the features and the values are a vector of strings
    map<string, vector<float>> dataMap;
public:
    explicit timeseries(const char *CSVFile);

    void extractToLines(const char *CSVFile);

    void extractValues(string &line);

    void extractNames(string &line);

    vector<string> getNames() const {
        return this->names;
    }

    map<string, vector<float>> getDataMap() const {
        return this->dataMap;
    }

    vector<float> getValuesByCount(int count)  {
        return this->dataMap[this->names[count]];
    }

    vector<float> etValuesByName(const string &Name) {
        return this->dataMap[Name];
    }
};
typedef timeseries TimeSeries;
#endif //ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H