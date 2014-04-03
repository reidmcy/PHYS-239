//Question 1
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <math.h>
#include "discpp.h"


using namespace std;

Dislin G;
const int points = 10;

class DerivativeCalculator {
    double (*iF) (double);
    double iDx;
    public:
    void setDx(double aDx) {iDx = aDx;}
    double dx() {return iDx;}
    double deriv(double aX) {return ((*iF)(aX - 2*iDx) - 8*(*iF)(aX - iDx) + 8*(*iF)(aX+iDx) - (*iF)(aX+2*iDx))/(12*iDx);}
    DerivativeCalculator(double aDx, double aF(double))
        : iDx(aDx) {iF=aF;}
};

double fun(double x) {
    return x*x*x*x*x*x;
}

int main() {
    double del = 1.e-1;
    double xV = 1;
    DerivativeCalculator DC1(del, fun);
    float x[points], y[points];
    for (int l = 0; l < points; l++) {
        y[l] = log(DC1.deriv(xV) - 5.0);
        x[l] = DC1.dx();
        DC1.setDx(DC1.dx()/1.3);
    }
    G.metafl("PDF");
    G.disini();
    G.name("Step Length", "x");
    G.name("Error", "y");
    G.labels("EXP", "xy");
    G.incmrk(1);
    G.setscl(x, points, "X");
    G.setscl(y, points, "Y");
    //G.scale("LOG", "xy");
    float minX, maxX, minY, maxY, stepX, stepY;
    G.graf(minX, maxX, minX, stepX, minY, maxY, minY, stepY);
    G.curve(x, y, points);
    G.disfin();
}
