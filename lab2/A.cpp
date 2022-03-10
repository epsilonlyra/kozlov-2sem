#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}


float NaiveMean (float const psi[], float const pdf[], float const dv, unsigned size){
    float sum = 0.f;
    for (unsigned idx = 0; idx < size; idx++){
        sum += psi[idx] * pdf[idx];
        }
    return dv * sum;
}

float RecurMean (float const psi[], float const pdf[], float const dv, unsigned size){
    if (size == 1) {
        return (psi[0] * pdf[0]);
        }
    else {
        return RecurMean(psi, pdf, dv, size / 2);
    }
}




int main(){

cout << setprecision(100) << fixed;

float const T = 1;
float const infparam = 10000; // это что стоит в экспоненте when the cut the graph
float vmax = sqrt(T * infparam);
unsigned const size = 2;
float dv = 2 * vmax / (size);

float pdf[size];
float psi[size];
for (long int i = 0; i < size; i++){
    pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
    psi[i] = 1;
}

cout << RecurMean(psi, pdf, dv, size);






return 0;
}
