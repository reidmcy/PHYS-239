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
        void print() {
            cout << iA << endl << iB <<endl;
        }
};

Gas::Gas (double aA, double aB) {
    iA = aA;
    iB = aB;
}

class VanDerWaalsCalculator{
    public:
        Gas iGas;
        float iVolume[100]; //This means number of points cannot excede 100
        float iPressure[100];
        float iTemperature;
        float iNumberOfMoles;
        int iNumberOfPoints;

        VanDerWaalsCalculator(Gas aGas,double aMinimumVolume, double aMaximumVolume, double aTemperature, double aNumberOfMoles, int aNumberOfPoints);

        void generatePressure();
        void draw();
};

VanDerWaalsCalculator::VanDerWaalsCalculator(Gas aGas, double aMinimumVolume, double aMaximumVolume, double aTemperature, double aNumberOfMoles, int aNumberOfPoints) : iGas(aGas.iA,aGas.iB){
    //I need to study for a midterm
    float stepSize = (aMaximumVolume - aMinimumVolume) / aNumberOfPoints;
    for (int loop = 0; loop < aNumberOfPoints; loop++) {
        iVolume[loop] = stepSize * loop + aMinimumVolume;
    }
    iTemperature = aTemperature;
    iNumberOfMoles = aNumberOfMoles;
    iNumberOfPoints = aNumberOfPoints;
}

void VanDerWaalsCalculator::generatePressure() {
    for (int loop = 0; loop<iNumberOfPoints; loop++) {
        iPressure[loop] = pressure(iNumberOfMoles, iVolume[loop], iTemperature, iGas.iA, iGas.iB);
    }
}

void VanDerWaalsCalculator::draw() {
    Dislin g;
    g.metafl("PDF");
    g.qplot(iVolume,iPressure,iNumberOfPoints);
}

int main() {
    Gas Oxygen(0.027,0.0014);
    int numberOfPoints = 100;
    float minimumVolume = 1;
    float maximumVolume = 10;
    float temperature = 300;
    float numberOfMoles = 1;
    VanDerWaalsCalculator VDW(Oxygen, minimumVolume, maximumVolume, temperature, numberOfMoles, numberOfPoints);
    VDW.generatePressure();
    VDW.draw(); 
    return 0;
}
