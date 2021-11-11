//
// Created by daniel on 11/11/21.
//

#ifndef ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
#define ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
class TimeSeries{ /*...*/};
class AnomalyReport{
public:
    const string description;
    const long timeStep;
    AnomalyReport(string description, long timeStep) :
            description(description),timeStep(timeStep){}
};
class TimeSeriesAnomalyDetector {
public:
    virtual void learnNormal(const TimeSeries& ts)=0;
    virtual vector<AnomalyReport> detect(const TimeSeries& ts)=0;
    virtual ~TimeSeriesAnomalyDetector(){}
};
#endif //ANOMALY_DETECTION_UTIL_CPP_ANOMALYDETECTOR_H
