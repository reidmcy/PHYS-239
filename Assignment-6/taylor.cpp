//Question 4
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <math.h>
#include "discpp.h"


using namespace std;

Dislin G;
const int points = 10;

double fun(double x) {
    return x*x*x*x*x*x;
}

double deriv(double f(double), double aX, double aDel) {
    return (f(aX + aDel) - f(aX)) / aDel;
}

int main() {
    double del = 0.1;
    double xV = 1;
    float x[points] , y[points];
    for (int l =0; l < points; l++) {
        y[l] = log(deriv( fun, xV, del) - 5);
        x[l] = del;
        del /=1.3;
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
