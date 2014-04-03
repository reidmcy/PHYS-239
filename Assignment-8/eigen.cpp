//Question 3
//Reid McIlroy-Young
//20416412
//March 11,2014

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const int matrixSize = 2; // cannot be other than 2

double determinant(double matrix[matrixSize][matrixSize]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

double dotProduct(double x1[matrixSize], double x2[matrixSize]) {
    cout << "dotProduct " << x1[0]*x2[0] + x1[1]*x2[1] << endl;
    return x1[0]*x2[0] + x1[1]*x2[1];
    
}

class EigenvalueSolver {
    public:
    double* iMatrix[matrixSize];
    double estimate, iError;
    double* iVector;
    double* oVector;

    void compute();
    void normalizeEigenvector();
    void print();
    EigenvalueSolver(double matrix[matrixSize][matrixSize], double initialEstimate, double resultVector[matrixSize], double eigenvector[matrixSize], double error);
};

EigenvalueSolver::EigenvalueSolver(double matrix[matrixSize][matrixSize], double initialEstimate, double resultVector[matrixSize], double eigenvector[matrixSize], double error) {
    for (int loop = 0; loop < matrixSize; loop++) {
        iMatrix[loop] = matrix[loop];
    }
    estimate = initialEstimate;
    iVector = eigenvector;
    oVector = resultVector;
    iError = error;
}

void EigenvalueSolver::compute() {
    double newEstimate;
    double newVector[matrixSize];
    double lambdaInverse[matrixSize][matrixSize];
    double tempMatrix[matrixSize][matrixSize];
    double dif;
    do {
        for (int loop = 0; loop < matrixSize; loop++) {
            for (int iloop = 0; iloop < matrixSize; iloop++) {
                tempMatrix[loop][iloop] = iMatrix[loop][iloop];
                if (loop == iloop) {
                    tempMatrix[loop][iloop] -= estimate;
                }
            }
        }
        double det = determinant(tempMatrix);
        cout << "det " << det << '\t';
        lambdaInverse[0][0] = tempMatrix[1][1] / det;
        lambdaInverse[0][1] = - tempMatrix[0][1] / det;
        lambdaInverse[1][0] = - tempMatrix[1][0] / det;
        lambdaInverse[1][1] = tempMatrix[0][0] / det;
        newVector[0] = lambdaInverse[0][0] * iVector[0] + lambdaInverse[0][1] * iVector[1];
        newVector[1] = lambdaInverse[1][0] * iVector[0] + lambdaInverse[1][1] * iVector[1];
        newEstimate = estimate + (dotProduct(newVector, iVector)) / (dotProduct(newVector, newVector));
        cout << "Est " << newEstimate << endl;
        dif = fabs(newEstimate) + fabs(estimate);
        estimate = newEstimate;
        iVector = newVector;
        if (fabs(iVector[0]) > 10) {
            normalizeEigenvector();
        }
        //break;
    }
    while (dif > iError);
}

void EigenvalueSolver::normalizeEigenvector() {
    double absValue = sqrt(iVector[0]*iVector[0] + iVector[1]*iVector[1]);
    iVector[0] = iVector[0] / absValue;
    iVector[1] = iVector[1] / absValue;
}

void EigenvalueSolver::print() {
    cout << "The eigenvalue is " << estimate << endl;;
}

int main() {
    double matrix[matrixSize][matrixSize] = {{1, 2}, {3, 8}};
    double initialEstimate = 0.8;
    double eigenvector[matrixSize] ={.1, -0.8};
    double resultVector[matrixSize];
    double error = 1.e-4;
    EigenvalueSolver ES(matrix, initialEstimate, resultVector, eigenvector, error);
    ES.compute();
    ES.normalizeEigenvector();
    ES.print();
}
