#include<iostream>
#include<cmath>
#include<iomanip>
#include<limits>
using namespace std;

float Maxwell(float T, float v){
    return 1.0f / (sqrt(T * M_PI)) * exp(-v * v / T);


}


float NaiveMean (float *psi, float *pdf, float const dv, unsigned size){
    float sum = 0.f;
    for (unsigned idx = 0; idx < size; idx++){
        sum += psi[idx] * pdf[idx];
        }
    return dv * sum;
}

int main(){

cout << setprecision(10) << fixed;

float const T = 1;
float const infparam = 100; // это что стоит в экспоненте когда мы отрезаем график
float vmax = sqrt(T * infparam);
unsigned const size = 1000;
float dv = 2 * vmax / (size);

float *pdf =  new float [size];
float *psi = new float [size];
for (long int i = 0; i < size; i++){

    pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
    psi[i] = 1;
}

cout << NaiveMean(psi, pdf, dv, size);

return 0;
}
