
#include "SimpleAnomalyDetector.h"
#include "AnomalyDetector.h"
#include <cmath>
#include "timeseries.h"

//create points of the two correlated features
Point* createPoints(map<string, vector<float>>&data,int size,string firstName, string secondName){
    Point* points= new Point[size];
    for(int i=0;i<size;++i)
    {
        float x= data[firstName][i];
        float y= data[secondName][i];
        points[i] =  Point(x,y);
    }
    return points;
}

// learns a normal file
void SimpleAnomalyDetector::learnNormal(const timeseries &ts) {
    vector<string> names = ts.getNames();
    map<string, vector<float>> data (ts.getDataMap());
    unsigned long valuesNum = data[names[0]].size();
    float correlation;
    string nameOther;
    vector<float *>pointers;
    for (auto name : names) {
        pointers.push_back(&data[name][0]);
    }
    int isFoundCorr;
    for (auto t = names.begin(); t != names.end(); ++t) {
        float currThreshold = 0.9;
        isFoundCorr=0;
        for (auto k = t + 1; k != names.end(); ++k) {
            // finds the correlation of the two columns.
            correlation = fabs(pearson(pointers[t-names.begin()], pointers[k-names.begin()], valuesNum));
            if (correlation > currThreshold) {
                currThreshold = correlation;
                nameOther = *k;
                isFoundCorr =1;
            }
        }
        if(isFoundCorr)
        {
            //creating the reg_line according to the data points of the two correlated features
            Point* points = createPoints(data,valuesNum,*t,nameOther);
            Line line= linear_reg(&(points),valuesNum);
            float maxDev=dev(*(points),line);
            for(int i=1;i<valuesNum;++i)
            {
                float currentDev= dev(*(points+i),line);
                if(currentDev>maxDev){
                    maxDev = currentDev;
                }
            }
            correlatedFeatures* cf=new correlatedFeatures(*t,nameOther,currThreshold,line,
                                                          maxDev*1.1);
            v.push_back(*cf);
            delete points;
        }
    }
}

//detects anomalies in the test file
vector<AnomalyReport> SimpleAnomalyDetector::detect(const timeseries &ts) {
    vector<AnomalyReport> reports;
    vector<string> names = ts.getNames();
    map<string, vector<float>> data (ts.getDataMap());
    unsigned long valuesNum = data[names[0]].size();
    // going through all the correlatedFeatures found to find anomalies.
    for(correlatedFeatures i : this->v){
        Point* points = createPoints(data,valuesNum,i.getFeature1(),i.getFeature2());
        for(int j=0; j<valuesNum;j++){
            float currentDev = dev(*(points+j),i.getLine());
            if(currentDev>i.getThreshold()){
                AnomalyReport* report= new AnomalyReport(i.getFeature1()+"-"+i.getFeature2(),j+1);
                reports.push_back(*report);
            }
        }
        delete points;
    }
    return reports;
}

//correlatedFeatures constructor
correlatedFeatures::correlatedFeatures (string feature1,string feature2, float correlation,
                                        Line line, float threshold):feature1(feature1),feature2(feature2),
                                        corrlation(correlation), lin_reg(line),threshold(threshold){}
