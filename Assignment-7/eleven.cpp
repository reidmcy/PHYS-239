//Question 6
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <math.h>
#include "discpp.h"
#define ROOT10 3.162277

using namespace std;

double delta = 1.e-10;

Dislin G;

double eleven(double x) {
    return x*x*x*x*x*x*x*x*x*x*x;
}

double newton(double f(double), double x, double epsilon) {
    double xi = x - f(x) * 2. * delta / (f(x + delta) - f(x - delta));
    return ((f(xi - x) < epsilon) && (f(xi + x) < epsilon)) ? xi : newton(f, xi, epsilon);
}


int main() {
    double xi[11] = {0.1, 0.1/ROOT10, 0.01, 0.01/ROOT10, 0.001, 0.001/ROOT10, 0.0001, 
    0.0001/ROOT10, 0.00001, 0.00001/ROOT10, 0.000001};
    double xr[11];
    for (int loop = 0; loop < 11; loop++) {
        xr[loop] = newton(eleven, xi[loop], delta);
        xi[loop] = log(xi[loop]);
    }
    G.metafl("PDF");
    G.qplot(xi, xr, 11);
}
