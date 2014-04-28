//Question 5
//Reid McIlroy-Young
//20416412
//April 3, 2014 

#include <iostream>
#include <math.h>

using namespace std;

const int numberOfPoints = 200;
const double boundaryTemperature = 0;
const double amplitude = 1;
const double timestep = 0.001;
const double diffusionCostant = 0.01;
const int numberOfLoops = 10;
const int numberOfPropagationSteps = 10;

void triSolver(double a[numberOfPoints], double b[numberOfPoints], double c[numberOfPoints], double d[numberOfPoints], int numberOfPoints) {
    c[0] = c[0] / b[0];
    d[0] = d[0] / b[0];
    for (int loop = 0; loop < numberOfPoints - 1; loop++) {
        c[loop] = c[loop] / (b[loop] - a[loop]*c[loop - 1]);
        d[loop] = (d[loop] - a[loop]*d[loop - 1]) / (b[loop] - a[loop]*c[loop - 1]);
    }
    d[numberOfPoints - 1] = (d[numberOfPoints - 1] - a[numberOfPoints - 1]*d[numberOfPoints - 2]) / (b[numberOfPoints - 1] - a[numberOfPoints - 1]*c[numberOfPoints - 2]);
    for (int loop = numberOfPoints - 2; loop > 0; loop--) {
        d[loop] = d[loop] - c[loop] * d[loop + 1];
    }
}


int main() {
}

