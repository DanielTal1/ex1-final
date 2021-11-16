#include <cmath>
#include <iostream>

float average(float* a,int size){
    float sum = 0;
    for(int i=0; i<size; i++){
        sum+=a[i];
    }
    return sum/size;
}
// returns the variance of X and Y
float var(float* x, int size)
{
    float sum = 0, var = 0, mean = 0;
    for(int i = 0 ; i < size ; ++i)
    {
        mean += x[i];
    }
    mean /= (float)size;
    for(int i = 0 ; i < size ; ++i)
    {
        sum += (x[i] - mean) * (x[i] - mean);
    }
    return sum / (float)size;
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size){
    float sum=0;
    float Xaverage = average(x,size);
    float Yaverage= average(y,size);
    for(int i=0; i<size;i++){
        sum += (x[i]- Xaverage) * (y[i]-Yaverage);
    }
    return sum/(float)size;
}

// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size)
{
    return cov(x, y, size) / (float)sqrt((double)var(x, size) * var(y, size));
}

class Line{
public:
    float a,b;
    Line():a(0),b(0){}
    Line(float a, float b):a(a),b(b){}
    float f(float x){
        return a*x+b;
    }
};

class Point{
public:
    float x,y;
    Point(float x, float y):x(x),y(y){}
};

// performs a linear regression and return s the line equation
Line linear_reg(Point** points, int size)
{
    float x[size], y[size], a, b;
    for(int i = 0 ; i < size ; ++i)
    {
        x[i] = (*points+i)->x;
        y[i] = (*points+i)->y;
    }
    a = cov(x, y, size)/ var(x, size);
    b = average(y, size) - a * average(x, size);
    return {a, b};
}



// returns the deviation between point p and the line
float dev(Point p,Line l){
    return fabs(l.a*p.x+l.b-p.y);
}
// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size){
    dev(p,linear_reg(points,size));
}