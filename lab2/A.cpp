#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}

float RecurMean (float *psi, float *pdf, float const dv, unsigned size){
    if (size == 1) {
        return dv * (psi[0] * pdf[0]);
        }
    else {
        return RecurMean(psi, pdf, dv, size / 2) + RecurMean(&psi[size / 2], &pdf[size / 2], dv, (size - size / 2));
    }
}




int main(){

cout << setprecision(21) << fixed;

float const T = 1;
float const infparam = 100000; // это что стоит в экспоненте when the cut the graph
float vmax = sqrt(T * infparam);
unsigned const size = 10000000;
float dv = 2 * vmax / (size);

float *pdf = new float [size];
float *psi = new float [size];
for (long int i = 0; i < size; i++){
    pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
    psi[i] = abs(-vmax + (i + 0.5) * dv);
}

cout << RecurMean(psi, pdf, dv, size);






return 0;
}
