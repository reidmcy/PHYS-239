//Question 2
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

int *myfunction(int *aI, int *aJ) {
    *aI = *aI * (*aJ);
    return aI;
}

int main () {
    int *aI;
    int *aJ;
    *aI = 2; //Error occurs here, pointers are not ints and cannot be assigned as such 
    *aJ = 3;
    
    cout << (*myfunction (aI, aJ) ) << endl;
}
