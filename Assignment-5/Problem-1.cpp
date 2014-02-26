//Question 1
//Reid McIlroy-Young
//20416412
//February 25,2014

#include <iostream>
#include <fstream>
using namespace std;

const int dim = 2;

int main(int argc, char* argv[]) {
    ifstream f;
    if (argc == 1) {
        cout << "No file give." << endl;
        return 0;
    }
    else {
        f.open(argv[1]);
    }
    int** m1;
    int** m2;
    int** m3;
    m1 = new int*[dim];
    m2 = new int*[dim];
    m3 = new int*[dim];
    for (int loop = 0; loop < dim; loop++) {
        m1[loop] = new int[dim];
        m2[loop] = new int[dim];
        m3[loop] = (int*) calloc(2, sizeof(int));
    }
    if (f) {
        f >> m1[0][0] >> m1[0][1] >> m1[1][0] >> m1[1][1];
        f >> m2[0][0] >> m2[0][1] >> m2[1][0] >> m2[1][1];

    }
    else {
        cout << "Not a valid file." << endl;
        return 0;
    }
    for (int leftLoop = 0; leftLoop < dim; leftLoop++) {
       for (int rightLoop = 0; rightLoop < dim; rightLoop++) {
           for (int innerLoop = 0; innerLoop < dim; innerLoop++) {
               m3[leftLoop][rightLoop] += m1[leftLoop][rightLoop] * m2[leftLoop][rightLoop];
           }
       }
    }        
    //cout << m1[0][0] << m1[0][1] << m1[1][0] << m1[1][1] << endl;
    //cout << m2[0][0] << m2[0][1] << m2[1][0] << m2[1][1] << endl;
    //cout << m3[0][0] << m3[0][1] << m3[1][0] << m3[1][1] << endl;
    for (int loop; loop < dim; loop++) {
        free(m1[loop]);
        free(m2[loop]);
        free(m3[loop]);
    }
    free(m1);
    free(m2);
    free(m3);
}

/*
Input:

1 2
3 4
5 6
7 8

Two 2x2 matrices take as commandline arguments
first is [[1,2],[3,4]]
secon is [[5,6],[7,8]]
*/
