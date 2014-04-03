//Question 2 
//Reid McIlroy-Young
//20416412
//January 28 2014

#include <iostream>
#include "discpp.h"

using namespace std;

Dislin g;

int main() {
    int numberOfPoints = 2;
    float x[2] = {0, 1};
    float y[2] = {0, 2};
    g.metafl("PDF");
    g.qplot(x, y, numberOfPoints);
}
