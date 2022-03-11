#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}

float CycleMean (float *psi, float *pdf, float const dv, unsigned const  size){

    float *x = new float [size];
    for (int i = 0; i < size; i++){
        x[i] = psi[i] * pdf[i];
    }
    for (int k = 2; k < 2 * size; k *= 2){

        for (int j = 0; j < size; j += k){
            if ((j + k/2) < size){
                x[j] = x[j] + x[j + k / 2];
                }
            else{
                x[j] = x[j];
            }
        }
    }
    return dv * x[0];
}




int main(){

cout << setprecision(10) << fixed;

float const T = 1;
float const infparam = 100; // это что стоит в экспоненте when the cut the graph
float vmax = sqrt(T * infparam);
unsigned const size = 10000000;
float dv = 2 * vmax / (size);

float *pdf = new float [size];
float *psi = new float [size];
for (long int i = 0; i < size; i++){
    pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
    psi[i] = abs(-vmax + (i + 0.5) * dv);
    //psi[i] = 1;
}

cout << CycleMean(psi, pdf, dv, size);

return 0;
}
