#include <iostream>
#include <discpp.h>

Dislin g;

const double km = 1000;
const double gravitationalConstant =6.67e-11;
const double earthMass = 5.97e24;
const double earthRadius = 6380 * km;
const int matSize = 20;

double gravitationalField(double aX, double aY) {
    double distance = aX * aX + aY * aY;
    double massxG = gravitationalConstant * earthMass; 
    if (distance > earthRadius)
        return massxG / distance;
    else 
        return massxG * distance / earthRadius;
}

int main() {
    double position[matSize];
    float field[matSize][matSize];
    float offset = matSize / 2 - 0.5;
    for (int loop = 0; loop < matSize; loop++) {
        position[loop] = 0.1 * earthRadius * (loop - offset);
    }
    float x, y;
    for (int outerLoop = 0; outerLoop < matSize; outerLoop++) {
        x = position[outerLoop];
        for (int innerLoop = 0; innerLoop < matSize; innerLoop++) {
            y = position[innerLoop];
            field[outerLoop][innerLoop] = gravitationalField(x, y);
        }
    }
    g.metafl("PDF");
    g.disini( );
    int iPlot = 2;
    if (iPlot == 1)
        g.qplsur((float*) field, matSize, matSize);
    else if (iPlot == 2)
        g.qplclr((float*) field, matSize, matSize);
    else {
        int numberOfContours = 30;
        g.qplcon((float*) field, matSize, matSize, numberOfContours);
    }
}
