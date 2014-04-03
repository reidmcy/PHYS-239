//Question 9
//Reid McIlroy-Young
//20416412
//April 3, 2014 

#include <iostream>
#include <math.h>
#include <discpp.h>

using namespace std;

Dislin G;

const double a = 1;
const double b = 0;
const double c = 0.3;
const double F = 10;
const double dt = 0.03;
const double x0 = 1;
const double v0 = 6;
const int steps = 40000;

double acceleration(double v, double x, double t) {
    return -(a*x*x*x + c*v) + F*cos(t); //b*x omitted since it is 0
}

void euler(double f(double, double, double), double x[steps], double v[steps], double t[steps], double del) {
    //euler method for 2nd order ODEs
    for (int loop = 1; loop < steps; loop++) {
        x[loop] = x[loop - 1] + v[loop - 1] * del;
        v[loop] = v[loop - 1] + f(v[loop - 1], x[loop - 1], t[loop - 1]) * del;
        t[loop] = t[loop - 1] + del;
    }
}

int main() {
    double X[steps], V[steps], T[steps];
    X[0] = x0;
    V[0] = v0;
    T[0] = 0;
    euler(acceleration, X, V, T, dt);
    float minX, maxX, minY, maxY, stepsX, stepsY;
    G.metafl("XWIN");
    G.disini();
    G.setscl(X, steps, "X");
    G.setscl(V, steps, "Y");
    G.incmrk(-1);
    G.marker(21);
    G.hsymbl(2);
    G.graf(minX, maxX, minX, stepsX, minY, maxY, minY, stepsY);
    G.curve(X, V, steps);
    G.endgrf();
    G.disfin();
}


