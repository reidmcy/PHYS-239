//Question 7
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

int main ( ) {
    const int j[4] = {1, 2, 3, 4};
    int *k =&j; //Error here assigning an int* to an const int*
    k[2] = 10;
    cout << j[2] << endl;
}
