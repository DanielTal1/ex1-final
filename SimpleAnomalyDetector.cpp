
#include "SimpleAnomalyDetector.h"
#include "AnomalyDetector.h"


void SimpleAnomalyDetector::learnNormal(const timeSeries &ts) {
    vector<string> names = ts.getNames(), column;
    map<string, vector<string>> data = ts.getDataMap();
    float correlation, currThreshold = 0.4;
    string name;
    int isFoundCorr;
    for (auto t = names.begin(); t != names.end(); ++t) {
        isFoundCorr=0;
        auto *dataStrings1 = (string *) &t->data()[0];
        float *x = nullptr;

        for (int i = 0; i < dataStrings1->length(); ++i) {
            *(x + i) = atof(dataStrings1[i].c_str());
        }
        float *y = nullptr;
        for (auto k = t + 1; k != names.end(); ++k) {
            auto *dataStrings2 = (string *) &k->data()[0];

            for (int i = 0; i < dataStrings2->length(); ++i) {
                *(x + i) = atof(dataStrings2[i].c_str());
            }
            correlation = pearson(x, y, dataStrings2->length());
            if (correlation > currThreshold) {
                currThreshold = correlation;
                name = *k;
                isFoundCorr =1;
            }

        }
        if(isFoundCorr)
        {
            Point* points;
            for(int i=0;i<dataStrings1->length();++i)
            {
                *(points+i) =  Point(*(x+i),*(y+i));
            }
            v.assign(1,correlatedFeatures(*t+"-"+name,correlation,
                                            linear_reg(&points,dataStrings1->length())));
        }

    }


}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const timeSeries &ts) {
    // TODO Auto-generated destructor stub
}

correlatedFeatures::correlatedFeatures(basic_string<char> basicString, float d, Line line) {

}
