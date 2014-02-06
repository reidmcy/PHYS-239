//Question 2
//Reid McIlroy-Young
//20416412
//February 4,2014

#include <iostream>
using namespace std;

class Rectangle {
    private:
        double iLength, iWidth;
    public:
        void widthSet(double aWidth) {
            iWidth = aWidth;
        }
        double widthGet() {
            return iWidth;
        }
        void lengthSet(double aLength) {
            iLength = aLength;
        }
        double lengthGet() {
            return iLength;
        }
        void functionarea() {
            long double a = iLength * iWidth;
            cout << "Area: " << a << endl;
        }
        Rectangle(double aWidth, double aLength) {
            iWidth = aWidth;
            iLength = aLength;
        };
};

int main() {
    Rectangle Rect(20, 10);
    Rect.functionarea();
}

/*
 Output: Area: 200
 */
