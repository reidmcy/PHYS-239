//Question 1
//Reid McIlroy-Young
//20416412
//February 4, 2014


#include <iostream>
using namespace std;

class Semiconductor {
    double iElectronDensity, iHoleDensity, iIntrinsicCarrierDensity;
    public:
        double electronDensity() {return iElectronDensity;};
        double holeDensity() {return iHoleDensity;};
        double intrinsicCarrierDensity() {return iIntrinsicCarrierDensity;};
        void setElectronDensity(double aElectronDensity) {
            iElectronDensity = aElectronDensity;
            iHoleDensity = iIntrinsicCarrierDensity / aElectronDensity;
        }
        void setHoleDensity(double aHoleDensity) {
            iHoleDensity = aHoleDensity;
            iElectronDensity = iIntrinsicCarrierDensity / aHoleDensity;
        }
        void print() {
            cout << "Carriers: " << iIntrinsicCarrierDensity << " Holes: " << iHoleDensity << " Electrons: " << iElectronDensity << endl;
        }
        Semiconductor(double aIntrinsicCarrierDensity) {
            iIntrinsicCarrierDensity = aIntrinsicCarrierDensity;
        };
};

int main() {
    Semiconductor Silicon(1.5E10);
    Silicon.setElectronDensity(1.e10);
    Silicon.print();
}

/*
 Output: Carriers: 1.5e+10 Holes: 1.5 Electrons: 1e+10
 */
