//Question 9
//Reid McIlroy-Young
//20416412
//April 3, 2014 

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <discpp.h>

using namespace std;

Dsilin G;

double circle(double x) {
    return sqrt(1 - x*x);
}

double normRand() {

    return rand() / (double) RAND_MAX;
    }

double integral(double f(double), int step, double xMin, double xMax, double yMax) {
    //Assumes 0 as lower y bound
    double A = (xMax - xMin) * yMax;
    double scale = xMax - xMin;
    int pointsIn = 0;
    for (int loop = 0; loop < step; loop++) {
        pointsIn += (f(normRand() * scale) > (yMax * normRand())) ? 1 : 0;
    }
    return (pointsIn / (double) step) * A;
}


int main() {
    srand(1396497803);
    double integrals[10];
    int steps[10];
    for (int loop = 0; loop < 10; loop++) {
        int two = 1;
        for (int loop2 = 0; loop2 < loop; loop2++) {
            two = two * 2;
        }
        steps[loop] = two * 1000;
        integrals[loop] =  4 *integral(circle, two*1000, 0, 1, 1);
        cout << 4 * integral(circle, two*1000, 0, 1, 1) << endl; 
    }




}
