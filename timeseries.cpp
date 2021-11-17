
#include "AnomalyDetector.h"
#include "timeseries.h"

using namespace std;


//extracting all the values of features
void timeseries::extractValues(string &line) {
    istringstream s(line);
    string value;
    int count = 0;
    while (getline(s, value, ',')) {
        dataMap[this->names[count]].push_back(stof(value));
        count++;
    }
}

// extracting the names of all the features into names vector
void timeseries::extractNames(string &line) {
    istringstream s(line);
    string name;
    while (getline(s, name, ',')) {
        this->names.push_back(name);
    }
}

//separates the file into lines
void timeseries::extractToLines(const char *CSVFile) {
    ifstream infile(CSVFile);
    vector<string> features;
    string line;
    int count = 0;
    while (getline(infile, line, '\n')) {
        if (count == 0) {
            extractNames(line);
        } else {
            extractValues(line);
        }
        count++;
    }
}

//timeseries constructor
timeseries::timeseries(const char *CSVFile) {
    extractToLines(CSVFile);
}


