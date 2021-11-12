#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class timeSeries{
    // saving the names in a vector in their original order
    vector<string> names;
    //saving the data in a map, the keys are the names of the features and the values are a vector of strings
    map<string,vector<std::string>> dataMap;

    explicit timeSeries(const char* cvsFile){
        extractToLines(cvsFile);
        }
    void extractToLines(const char* cvsFile){
        ifstream infile(cvsFile);
        vector<string> features;
        string line;
        int count=0;
        while (getline(infile, line,'\n'))
        {
            if(count==0){
                extractNames(line);
            }
            else{
                extractValues(line);
            }
            count++;
        }
    }
    //extracting all the values of features
    void extractValues(const string& line){
        istringstream s(line);
        string value;
        int count=0;
        while (getline(s, value,',')){
            dataMap[this->names[count]].push_back(value);
            count++;
        }
    }

    // extracting the names of all the features into names vector
    void extractNames(const std::string& line){
        istringstream s(line);
        string name;
        while (getline(s, name,',')){
            this->names.push_back(name);
        }
    }

    vector<string>& getNames(){
        return this->names;
    }

    map<string,vector<std::string>>& getDataMap(){
        return this->dataMap;
    }
    vector<string>& getValuesByCount(int count) {
        return this->dataMap[this->names[count]];
    }
    vector<string>& getValuesByName(const string& Name){
        return this->dataMap[Name];
    }
};
