//Question 3
//Reid McIlroy-Young
//20416412
//February 4, 2014

#include <iostream>
#include <stdlib.h>
using namespace std;

class Vector{
    double iArray[1000];
    int lArraySize;
    public:
        double getArrayElement(int aPosition) {
            if (aPosition < 0 || aPosition > 999) {
                 exit(0);
            }
            else {
                return iArray[aPosition];
            }
        }
        int getArraySize() {
            return lArraySize;
        }
        void addLastElement(double aArrayElement) {
            if (lArraySize < 1000) {
                iArray[lArraySize] = aArrayElement;
                lArraySize++;
            }
            else {
                exit(0);
            }
        }
        void changeArrayElement(int aPosition, double aElementValue) {
            if (aPosition > lArraySize || aPosition < 0) {
                exit(0);
            }
            else {
                iArray[aPosition] = aElementValue;
            }
        }
        void printArray() {
            for (int loop = 0; loop < lArraySize; loop++) {
                if (loop == 0) {
                    cout << iArray[loop];
                }
                else if (loop % 10 == 0) {
                    cout << endl << iArray[loop];
                }
                else {
                    cout << ' ' << iArray[loop];
                }
            }
            cout << endl;
        }
        Vector(double aArray[1000], int aArraySize) {
            lArraySize = aArraySize;
            for (int loop = 0; loop < lArraySize; loop++) {
                iArray[loop] = aArray[loop];
            }
        }
};

int main() {
    double aArray[4] ={1,2,4,9};
    Vector Vec(aArray, 4);
    Vec.changeArrayElement(2, 5);
    Vec.addLastElement(10);
    cout << "Vec Size: " << Vec.getArraySize() << endl;
    cout << "Vec[3]: " << Vec.getArrayElement(3) << endl;
    Vec.printArray();
}

/*
Output:
Vec Size: 5
Vec[3]: 9
1 2 5 9 10
*/
