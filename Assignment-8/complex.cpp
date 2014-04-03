//Question 2
//Reid McIlroy-Young
//20416412
//March 25,2014

#include <iostream>
#include <complex>

using namespace std;

const int n = 3;
const complex <double> CI = complex <double> (0.0,1.0);

void gauss( complex <double> aA[][n], complex <double> aC[], complex <double> aB[]) {
    for (int i = 0; i < n; i++) {
        if (!abs(aA[i][i])) {
            throw 0;
        }
        for (int j = i + 1; j < n; j++) {
            complex <double> d = aA[j][i]/aA[i][i];
            for (int k = i + 1; k < n; k++) {
                aA[j][k] -= d * aA[i][k];
            }
            aB[j] -= d * aB[i];
        }
    }
    if (!abs(aA[n-1][n-1])) {
        throw 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        aC[i] = aB[i];
        for (int j = i + 1; j < n; j++) {
            aC[i] -= (aA[i][i]) * (aC[j]);
        }
        aC[i] /= aA[i][i];
    }
}

void printMatrix(complex <double> aA[n][n]) {
    for (int loop = 0; loop < n; loop++) {
        for (int iloop = 0; iloop < n; iloop++) {
            cout << aA[loop][iloop];
            if (iloop < n - 1) {
                cout << '\t';
            }
        }
        cout << endl;
    }
}

void printVector(complex <double> aV[n]) {
    for (int loop = 0; loop < n; loop++) {
        cout << aV[loop] << endl;
    }
}


int main() {
    complex <double> A[n][n] = {{1, 0, CI}, {-CI, 1, -CI}, {-1, 0, CI}};
    complex <double> B[n] = {CI, 0, -CI};
    cout << "Input Matrix:" << endl;
    printMatrix(A);
    cout << "Input Vector:" << endl;
    printVector(B);
    complex <double> C[n];
    gauss(A, C, B);
    cout << "Final Vector:" << endl;
    printVector(C);
}

