#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}

float KehanMean (float *psi, float *pdf, float const dv, unsigned size){
    float sum, c, t, y;
    sum = c = t = y =  0.0;

    for (long int i = 0; i < size; i++){
        y = dv * pdf[i] * psi[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return  sum;
}




int main(){

cout << setprecision(15) << fixed;

float const T = 1;
float const infparam = 100; // это что стоит в экспоненте when the cut the graph
float vmax = sqrt(T * infparam);
unsigned const size = 10000;
float dv = 2 * vmax / (size);

float *pdf = new float [size];
float *psi = new float [size];
for (long int i = 0; i < size; i++){
    pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
    psi[i] = 1;
}

cout << KehanMean(psi, pdf, dv, size);

return 0;
}
