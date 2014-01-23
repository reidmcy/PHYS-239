#include <iostream>
using namespace std;

double m = 1;
double h = 0.1;
double vi = 10;
double xi = 0;
double g = -9.8;

int t[100] = {0};
double x[100] = {0};
double v[100] = {0};
double a[100] = {0};

/*double f(x) = {
	return 9.8/1;
}
*/


int main()
{
	//cout << a <<endls;
	for (int i = 0; i < 100; i++) {
		t[i] = i;
		a[i] = g/m;
		(t[i] == 0) ? (v[i] = vi) : (v[i] = v[i - 1] + a[i] * h);
		(t[i] == 0) ? (x[i] = xi) : (x[i] = x[i - 1] + v[i] * h);
		cout << t[i] << " " << a[i] << " " << v[i] << " " << x[i] << endl;
		}


}
