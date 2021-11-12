//
// Created by daniel on 11/11/21.
//

#ifndef ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
#define ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H

using namespace std;
class timeSeries{ /*...*/};
class AnomalyReport{
public:
    const string description;
    const long timeStep;
    AnomalyReport(string description, long timeStep) :
            description(description),timeStep(timeStep){}
};
class TimeSeriesAnomalyDetector {
public:
    virtual void learnNormal(const timeSeries& ts)=0;
    virtual vector<AnomalyReport> detect(const timeSeries& ts)=0;
    virtual ~TimeSeriesAnomalyDetector(){}
};
#endif //ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
