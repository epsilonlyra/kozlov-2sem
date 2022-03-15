#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}

void Split(float const x, float &x_h, float &x_l) {
  auto c = static_cast<float>((1ul << 11) + 1ul);
  x_h = (c * x) + (x - (c * x));
  x_l = x - x_h;
}

void TwoMult(float const a, float const b, float &s, float &t) {
  float  a_high, a_low, b_high, b_low;
  Split(a, a_high, a_low);
  Split(b, b_high, b_low);
  s = a * b;
  t = -s + a_high * b_high;
  t += a_high * b_low;
  t += a_low * b_high;
  t += a_low * b_low;
}

float FmaMean (float *psi, float *pdf, float const dv, unsigned const  size){
    float sum = 0.0;

    float s = 0.0;
    float k = 0.0;
    float c = 0.0;

    float t = 0.0;
    float y = 0.0;



    for (long int i  = 0; i < size; i++){
        TwoMult(psi[i], pdf[i], s, k);
        y = s - c;
        t = sum + y;
        c = ((t - sum) - y) +  k;
        sum = t;
    }

    return dv * sum;
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

cout << FmaMean(psi, pdf, dv, size);

return 0;
}
