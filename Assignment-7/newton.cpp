//Question 4
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <math.h>

using namespace std;

const double delta = 1.e-4;

double fun(double x) {
    return x*sqrt( fabs(x));
}

double newton(double f(double), double x, double epsilon, int* iter) {
    *iter += 1;
    double xi = x - f(x) * 2. * delta / (f(x + delta) - f(x - delta));
    return ((f(xi - x) < epsilon) && (f(xi + x) < epsilon)) ? xi : newton(f, xi, epsilon, iter);
}

int main() {
    int it = 0; 
    double xi = 0.1;
    cout << "The point calculated for xsqrt(abs(x)) is: " << newton(fun, xi, delta, &it);
    cout << " it took " << it << " iterations." << endl;
    it = 0;
    cout << "The point calculated for s(x) is: " << newton(sin, xi, delta, &it);
    cout << " it took " << it << " iterations." << endl;
    }
