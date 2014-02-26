//Question 11
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

class MyClass2;

class MyClass1 {
    public:
        MyClass1() : iA(0) {}
        MyClass1(int aIA) : iA(aIA) {} //casting int to double
        MyClass1(MyClass2);
        double getIA() { return (iA);
        }
    private:
    double iA;
};

class MyClass2 {
    public:
        MyClass2() : iB(0) {}
        MyClass2(int aIB) : iB(aIB) {}
        MyClass2(MyClass1 aMyClass1) {iB = aMyClass1.
         getIA()/2.;}
        double getIB(){ return iB;
        }
    private:
        double iB;
};

MyClass1::MyClass1(MyClass2 aMyClass2) {iA = 2*aMyClass2.
 getIB();}

int main() {
    MyClass1 MyClass1Object1(3.5);
    MyClass1 MyClass1Object2;
    MyClass2 MyClass2Object1;
    MyClass2Object1 = MyClass1Object1;
    MyClass1Object2 = MyClass2Object1;
    cout << MyClass1Object2.getIA() << endl;
}

/*
Output:
3
*/
    
