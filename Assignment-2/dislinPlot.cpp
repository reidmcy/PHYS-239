#include <iostream>
#include "discpp.h"

using namespace std;

Dislin g;

int main() {
    int numberOfPoints = 2;
    float x[2] = {0, 1};
    float y[2] = {0, 2};
    g.qplot(x, y, numberOfPoints);
}
