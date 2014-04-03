//Question 2
//Reid McIlroy-Young
//20416412
//January 28 2014

#include <iostream>
#include "discpp.h"
using namespace std;

double f( double aX) {
    return aX*aX;
}

Dislin g;

int main() {
    float x[11], y[11];
    double del = 0.1;
    for (int loop = 0; loop < 11; loop++) {
        x[loop] = loop * del;
        y[loop] = f(x[loop]);
    }
    g.metafl("PDF");
    g.disini();
    g.name("X-axis","X");
    g.name("Y-axis","Y");
    g.qplsca(x,y,11);
}
