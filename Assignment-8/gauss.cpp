//Question 1
//Reid McIlroy-Young
//20416412
//March 25,2014

#include <iostream>
#include <fstream>
#include <discpp.h>

using namespace std;

const int n = 3;

Dislin G;

double f(int i, double x) {
    if (i == 0) {
        return 1;
    }
    else if (i == 1) {
        return x;
    }
    else {
        return x * x;
    }
}

double outFun(double C[n], double fun(int, double), double x) {
    double ret = 0;
    for (int loop = 0; loop < n; loop++) {
        ret += C[loop] * fun(loop, x);
    }
    return ret;
}

void gauss( double aA[][n], double aC[], double aB[]) {
    for (int i = 0; i < n; i++) {
        if (!aA[i][i]) {
            throw 0;
        }
        for (int j = i + 1; j < n; j++) {
            double d =aA[j][i]/aA[i][i];
            for (int k = i + 1; k < n; k++) {
                aA[j][k] -= d * aA[i][k];
            }
            aB[j] -= d * aB[i];
        }
    }
    if (!aA[n-1][n-1]) {
        throw 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        aC[i] = aB[i];
        for (int j = i + 1; j < n; j++) {
            aC[i] -= aA[i][i] * aC[j];
        }
        aC[i] /= aA[i][i];
    }
}

int main() {
    ifstream F;
    F.open("data.dat");                         //opens data file
    double ti[7], ui[7];                        //xi stores first colums values, yi the second 
    for (int loop = 0; loop < 7; loop++) {      //This assumes 7 data points
        F >> ti[loop]; 
        F >> ui[loop];
        //cout << xi[loop] << '\t' << yi[loop] << endl;
    }
    double A[n][n] = {0};
    double b[n] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 7; k++) {
                A[i][j] += f(i, ti[k]) * f(j, ti[k]);
            }
        }
    }
    for (int j = 0; j < n; j++) {
            for (int k = 0; k < 7; k++) {
                b[j] += f(j,ti[k]) * ui[k];
            }
    }
    double c[n];
    gauss(A,c,b);
    double xi[7];
    for (int loop = 0; loop < 7; loop++) {
        xi[loop] = outFun(c, f, (1.9 * loop) / 7);
    }


    G.metafl("PDF");
    G.disini();
    G.name("t", "x");
    G.name("y", "y");
    G.incmrk(1);
    G.setscl(ti, 7, "x");
    G.setscl(ui, 7, "y");
    float minX, maxX, minY, maxY, stepX, stepY;
    G.graf(minX, maxX, minX, stepX, minY, maxY, minY, stepY);
    G.curve(ti, ui, 7);
    G.setscl(xi, 7, "y");
    G.curve(ti, ui, 7);
    G.disfin();

 

}
