
#include "timeSeries.h"

using namespace std;


//extracting all the values of features
void timeSeries::extractValues(string &line) {
    istringstream s(line);
    string value;
    int count = 0;
    while (getline(s, value, ',')) {
        dataMap[this->names[count]].push_back(value);
        count++;
    }
}

// extracting the names of all the features into names vector
void timeSeries::extractNames(string &line) {
    istringstream s(line);
    string name;
    while (getline(s, name, ',')) {
        this->names.push_back(name);
    }
}

void timeSeries::extractToLines(const char *CSVFile) {
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

timeSeries::timeSeries(const char *CSVFile) {
    extractToLines(CSVFile);
}




