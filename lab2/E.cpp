#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}

double DoubleRecurMean (float *psi, float *pdf, float const dv, unsigned size){
    if (size == 1) {
        return static_cast<double>(dv) * (static_cast<double>(psi[0]) * static_cast<double>(pdf[0]));
        }
    else {
        return DoubleRecurMean(psi, pdf, dv, size / 2) + DoubleRecurMean(&psi[size / 2], &pdf[size / 2], dv, (size - size / 2));
    }
}




int main(){

cout << setprecision(10) << fixed;

float const T = 1;
float const infparam = 100; // это что стоит в экспоненте when the cut the graph
float vmax = sqrt(T * infparam);
unsigned const size = 1000;
float dv = 2 * vmax / (size);

float *pdf = new float [size];
float *psi = new float [size];
for (long int i = 0; i < size; i++){
    pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
    //psi[i] = abs(-vmax + (i + 0.5) * dv);
    psi[i] = 1;
}

cout << DoubleRecurMean(psi, pdf, dv, size);

return 0;
}
