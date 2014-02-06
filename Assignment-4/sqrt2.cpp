//Question 1
//Reid McIlroy-Young
//20416412
//February 11,2014

#include <iostream>
using namespace std;

double sqrtAprox(int steps) {
    //Aproximates sqrt(2) - 1 using the series 1/ (2 + ( 1 / (2 + 1 / ( 2 + ..))))
    // steps gives the number of times the series is recursed
    // steps decrements each call of sqrtAprox and when it reachs 1 the value is returned
    if (steps <= 1) {
        return 0.5;
    }
    else {
        return 1 / ( 2 +  sqrtAprox(steps - 1));
    }
}

int main() {
    for (int loop = 1; loop < 11; loop++) {
        cout << "for n of " << loop << " sqrt(2) - 1 = " << sqrtAprox(loop) << endl;
    }
}

/*
Output:
for n of 1 sqrt(2) - 1 = 0.5
for n of 2 sqrt(2) - 1 = 0.4
for n of 3 sqrt(2) - 1 = 0.416667
for n of 4 sqrt(2) - 1 = 0.413793
for n of 5 sqrt(2) - 1 = 0.414286
for n of 6 sqrt(2) - 1 = 0.414201
for n of 7 sqrt(2) - 1 = 0.414216
for n of 8 sqrt(2) - 1 = 0.414213
for n of 9 sqrt(2) - 1 = 0.414214
for n of 10 sqrt(2) - 1 = 0.414214
*/
