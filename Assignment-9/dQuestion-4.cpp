//Question 4
//Reid McIlroy-Young
//20416412
//April 3, 2014 

#include <iostream>
#include <math.h>
#include <time.h>
#include <discpp.h>

#define PI 3.14159265359

using namespace std;

const int h = 40;
const int bins = 20;
Dislin G;

double piRand() {
    return rand() / (double) RAND_MAX * 2 * PI;
}

class Walker {
    public:
    double x, y;
    int steps;
    void step();
    void manySteps();
    double distance();
    Walker(int aSteps);
};

Walker::Walker(int aSteps) {
    steps = aSteps;
    x = 0;
    y = 0;
}

void Walker::step() {
    double theta = piRand();
    x += cos(theta);
    y += sin(theta);
}

void Walker::manySteps() {
    for (int loop = 0; loop < h; loop++) {
        step();
    }
}

double Walker::distance() {
    return sqrt( x*x + y*y);
}

void sort(double a[10000]) {
    double min;
    double temp;
    for (int loopO = 0; loopO < 1000; loopO++) {
        min = a[loopO];
        for (int loopI = loopO + 1; loopI < 1000; loopI++) {
            if (min > a[loopI]) {
                temp = min;
                min = a[loopI];
                a[loopI] = temp;
            }
        }
        a[loopO] = min;
    }
}

void bin(double a[1000], double binned[bins]) {
    sort(a);
    double min = a[0];
    double max = a[999];
    double binSize = (max - min) / bins;
    int cBin = 0;
    for (int loop = 0; loop < 1000; loop++) {
        if (a[loop] < binSize * (cBin + 1)) {
            binned[cBin] = binned[cBin] + 1;
        }
        else {
            //Assumes smooth distribution
            cBin++;
            binned[cBin] = binned[cBin] + 1;
        }
    }
}

int main() {
    double dist[10000];
    for (int loop = 0; loop < 10000; loop++) {
        Walker W(h);
        W.manySteps();
        dist[loop] = W.distance();
    }
    double hist[bins] = {0}; 
    bin(dist, hist);
    G.metafl("PDF");
    G.qplbar(hist, bins);
    return 0;
}
