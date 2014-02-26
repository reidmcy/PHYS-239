//Question 6
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

int main ( ) {
    int *a = new int[9];
    for (int loop = 0; loop < 9; loop++) a[loop] = loop;
    int **b = new int*[3];
    for (int loop = 0; loop < 3; loop++) b[loop] = a + 3*loop;
            for (int loopO = 0; loopO < 3; loopO++) {
                    for (int loopI = 0; loopI < 3; loopI++)
            b[loopI][loopO] = loopO;
            }
            delete [ ] a;
            cout << b[2][2];
            delete [ ] b;
}

/*
Output:
2*/
