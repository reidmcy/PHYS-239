//Question 1
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <math.h>
#include "discpp.h"

using namespace std;

Dislin G;

double fun(double x) {
    return x*x*x;
}

double simpRule(double f(double), double a, double b) {
    return (b - a) / 6 * (f(a) + 4 * f((a + b)/ 2) + f(b));
}

double simpInt(double f(double), double a, double b, int n) {
    if (n == 1) {throw "Error n";}
    double xi[n];
    xi[0] = a;
    double del = (b - a) / n;
    for (int loop = 1; loop < n; loop++) {
        xi[loop] = xi[loop - 1] + del;
    }
    if (xi[n - 1] > (b + del)) {
        cout << "2";
        throw "Error xi[n]";}
    double out = 0;
    for (int loop = 0; loop < n - 1; loop++) {
        out += simpRule(f, xi[loop], xi[loop + 1]);
    }
    return out;
}


int main() {
    int samples = 8; //Any higher results in int overflow
    int n[samples];
    double logN[samples];
    n[0] = 10;
    logN[0] = log(10);
    double y[samples];
    y[0] = simpInt(fun, 0, 1, n[0]);
    for (int loop = 1; loop < samples; loop++) {
        n[loop] = n[loop - 1] * 5;
        logN[loop] = log(n[loop]);
        y[loop] = simpInt(fun, 0, 1, n[loop]) - (1./4.);
    }
    G.metafl("PDF");
    G.qplot(logN, y, samples);
    }
