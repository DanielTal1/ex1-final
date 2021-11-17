//
// Created by daniel on 11/11/21.
//

#ifndef ANOMALY_DETECTION_UTIL_CPP_SIMPLEANOMALYDETECTOR_H
#define ANOMALY_DETECTION_UTIL_CPP_SIMPLEANOMALYDETECTOR_H
#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <algorithm>
using namespace std;
struct correlatedFeatures {
    correlatedFeatures(string feature1,string feature2, float correlation, Line line, float threshold);
    string feature1, feature2; // names of the correlated features
    float corrlation;
    Line lin_reg;
    float threshold;
public:
    string getFeature1(){
        return this->feature1;
    }
    string getFeature2(){
        return this->feature2;
    }
    float getCorrlation(){
        return this->corrlation;
    }
    Line getLine(){
        return this->lin_reg;
    }
    float getThreshold(){
        return this->threshold;
    }
};

class SimpleAnomalyDetector : public TimeSeriesAnomalyDetector {
    vector<correlatedFeatures> v;
public:
    SimpleAnomalyDetector() {}

    virtual ~SimpleAnomalyDetector() {};

    virtual void learnNormal(const timeseries &ts);

    virtual vector<AnomalyReport> detect(const timeseries &ts);

    vector<correlatedFeatures> getNormalModel() {
       return this->v;
    }
};
#endif //ANOMALY_DETECTION_UTIL_CPP_SIMPLEANOMALYDETECTOR_H
