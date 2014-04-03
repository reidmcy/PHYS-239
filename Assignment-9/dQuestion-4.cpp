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

int main() {
    double dist[10000];
    for (int loop = 0; loop < 10000; loop++) {
        Walker W(h);
        W.manySteps();
        dist[loop] = W.distance();
        cout << dist[loop] << endl;
    }
    
    return 0;
}
