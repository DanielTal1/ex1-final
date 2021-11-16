//
// Created by daniel on 11/11/21.
//

#ifndef ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H
#define ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class timeSeries {
    // saving the names in a vector in their original order
    vector<string> names;
    //saving the data in a map, the keys are the names of the features and the values are a vector of strings
    map<string, vector<std::string>> dataMap;
public:
    explicit timeSeries(const char *CSVFile);

    void extractToLines(const char *CSVFile);

    void extractValues(string &line);

    void extractNames(string &line);

    vector<string> getNames() const {
        return this->names;
    }

    map<string, vector<std::string>> getDataMap() const {
        return this->dataMap;
    }

    vector<string> getValuesByCount(int count)  {
        return this->dataMap[this->names[count]];
    }

    vector<string> etValuesByName(const string &Name) {
        return this->dataMap[Name];
    }
};

#endif //ANOMALY_DETECTION_UTIL_CPP_TIMESERIES_H
