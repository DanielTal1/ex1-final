#ifndef ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
#define ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
using namespace std;
#include <iostream>
#include <string>
#include "timeseries.h"


class AnomalyReport{
public:
    const string description;
    const long timeStep;
    AnomalyReport(string description, long timeStep) :
            description(description),timeStep(timeStep){}
};
class TimeSeriesAnomalyDetector {
public:
    virtual void learnNormal(const timeseries& ts)=0;
    virtual std::vector<AnomalyReport> detect(const timeseries& ts)=0;
    virtual ~TimeSeriesAnomalyDetector(){}
};
#endif //ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
