//Question 2
//Reid McIlroy-Young
//20416412
//February 11,2014

#include <iostream>
#include "discpp.h"

using namespace std;

const double R = 0.082;

float pressure(float aMoles, float aVolume, float aTemperature, float aA, float aB) {
    return (aMoles * R * aTemperature) / (aVolume - aB * aMoles) - (aA * aMoles * aMoles) / (aVolume * aVolume);
}


class Gas {
    public:
        double iA;
        double iB;
        Gas(double aA, double aB); 
};

Gas::Gas (double aA, double aB) {
    iA = aA;
    iB = aB;
}

class VanDerWaalsCalculator {
    public:
        Gas iGas;
        float iVolume[100]; //This means number of points cannot excede 100
        float iPressure[100];
        float iTemperature;
        float iNumberOfMoles;
        int iNumberOfPoints;

        VanderDerWaalsCalculator(Gas aGas, double aMinimumVolume, double aMaximumVolume, double aTemperature, double aNumberOfMoles, int aNumberOfPoints);

        void generatePressure();
        void draw();
};

VanDerWaalsCalculator::VanDerWaalsCalculator(Gas aGas, double aMinimumVolume, double aMaximumVolume, double aTemperature, double aNumberOfMoles, int aNumberOfPoints) {
    float stepSize = (aMaximumVolume - aMinimumVolume) / aNumberOfPoints;
    float VLoop = aMinimumVolume;
    for (int loop = 0; loop < aNumberOfPoints; loop++) {
        iVolume[loop] = stepSize * loop + aMinimumVolume;
        iPressure[loop] = pressure(aNumberOfMoles, iVolume[loop], aTemperature, aGas.iA, aGas.iB);
       }
    iGas = aGas;
}




int main() {
    return 0;
}
