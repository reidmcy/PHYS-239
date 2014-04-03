//Question 2
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <math.h>
#include "discpp.h"

using namespace std;

Dislin G;

double fun(double x) {
    return (x < 1.) ? 1. : 0.;
}

double rect(double f(double), double a, double b, int n) {
    double sum = 0;
    double dx = (b-a) / n;
    double x = dx / 2;
    for (int loop = 0; loop < n; loop++) {
        sum += f(x);
        x += dx;
    }
    return sum * dx;
}

int main() {
    int samples = 8; //Any higher results in int overflow
    int n[samples];
    double logN[samples];
    n[0] = 10;
    logN[0] = log(10);
    double y[samples];
    y[0] = rect(fun, 0, 2, n[0]);
    for (int loop = 1; loop < samples; loop++) {
        n[loop] = n[loop - 1] * 5;
        logN[loop] = log(n[loop]);
        y[loop] = rect(fun, 0, 2, n[loop]) - 1;
    }
    G.metafl("PDF");
    G.qplot(logN, y, samples);
}
