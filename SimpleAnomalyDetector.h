//
// Created by daniel on 11/11/21.
//

#ifndef ANOMALY_DETECTION_UTIL_CPP_SIMPLEANOMALYDETECTOR_H
#define ANOMALY_DETECTION_UTIL_CPP_SIMPLEANOMALYDETECTOR_H

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"

using namespace std;
struct correlatedFeatures {
    correlatedFeatures(basic_string<char> basicString, float d, Line line);

    string feature1, feature2; // names of the correlated features
    float corrlation;
    Line lin_reg;
    float threshold = 0.4;
};

class SimpleAnomalyDetector : public TimeSeriesAnomalyDetector {
    vector<correlatedFeatures> v;
public:
    SimpleAnomalyDetector() {}

    virtual ~SimpleAnomalyDetector() {};

    virtual void learnNormal(const timeSeries &ts);

    virtual vector<AnomalyReport> detect(const timeSeries &ts);

    vector<correlatedFeatures> getNormalModel() {
        vector<correlatedFeatures> v;
        return v;
    }
};

#endif //ANOMALY_DETECTION_UTIL_CPP_SIMPLEANOMALYDETECTOR_H
