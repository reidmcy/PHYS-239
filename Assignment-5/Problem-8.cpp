//Question 8
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
using namespace std;

int l = 5;
int *lp = &l;
int myFunction(int*(&p)) {
    p = lp;
    return *p;
}
int main ( ) {
    l = 4;
    int *p = &l;
    myFunction(p);
    cout << *p;
}
/*
Output:
4*/
