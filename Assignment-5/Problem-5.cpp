//Question 5
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

int *myFunction ( ) {
    int *aV = new int [3];
    for (int loop = 0; loop < 3; loop++) aV[loop] = loop;
    return aV;
}

int main ( ) {
    int *v;
    v = myFunction ( ) ;
    cout << v[1] << endl;
}

/*
Output:
1
*/
