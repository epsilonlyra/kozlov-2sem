#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;

float Maxwell(float T, float v){
    return 1/sqrt(T * M_PI) * exp(-v * v / T);


}

float NaiveMean (float *psi, float *pdf, float const dv, unsigned size){
    float sum = 0.f;
    for (unsigned idx = 0; idx < size; idx++){
        sum += psi[idx] * pdf[idx];
        }
    return dv * sum;
}

float RecurMean (float *psi, float *pdf, float const dv, unsigned size){

    if (size == 1) {
        return dv * (psi[0] * pdf[0]);
        }
    else {
        return RecurMean(psi, pdf, dv, size / 2) + RecurMean(&psi[size / 2], &pdf[size / 2], dv, (size - size / 2));
    }
}

double DoubleRecurMean (float *psi, float *pdf, float const dv, unsigned size){


    if (size == 1) {
        return static_cast<double>(dv) * (static_cast<double>(psi[0]) * static_cast<double>(pdf[0]));
        }
    else {
        return DoubleRecurMean(psi, pdf, dv, size / 2) + DoubleRecurMean(&psi[size / 2], &pdf[size / 2], dv, (size - size / 2));
    }
}
float CycleMean (float *psi, float *pdf, float const dv, unsigned size){

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

float KehanMean (float *psi, float *pdf, float const dv, unsigned size){
    float sum, c, t, y;
    sum = c = t = y = 0.0;

    for (long int i = 0; i < size; i++){
        y = pdf[i] * psi[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return  dv * sum;
}

int main(){

double const T = 1;
double const average = sqrt(T / M_PI);
float const infparam = 100; // это что стоит в экспоненте when the cut the graph
float vmax = sqrt(T * infparam);

ofstream fout("results.txt");

fout << T << ";" << infparam << ";";
fout << setprecision(10) << average << endl;

fout << "Разбиений" <<  ";Рекурсивное сложение" << ";Двойное Рекурсивное сложение" << ";Наивное сложение";
fout << ";Прореживающее сложение" << ";Кехановское сложение" << ";Совмещающее сложение" << endl;

fout << setprecision(10) << fixed;

for (unsigned size = 1000; size <= 50000; size += 5){


    float dv = 2 * vmax / (size);

    float *pdf = new float [size];
    float *psi = new float [size];
    for (long int i = 0; i < size; i++){
        pdf[i] = Maxwell(T, -vmax + (i + 0.5) * dv);
        psi[i] = abs(-vmax + (i + 0.5) * dv);
        //psi[i] = 1;
    }


    fout << size <<";";

    fout << static_cast<double>(RecurMean(psi, pdf, dv, size))- average<< ";";
    fout << static_cast<double>(DoubleRecurMean(psi, pdf, dv, size)) - average<< ";";
    fout << static_cast<double>(NaiveMean(psi, pdf, dv, size))- average << ";";
    fout << static_cast<double>(CycleMean(psi, pdf, dv, size))- average << ";";
    fout << static_cast<double>(KehanMean(psi, pdf, dv, size))- average << ";";
    fout << static_cast<double>(FmaMean(psi, pdf, dv, size))- average;

    fout << endl;

    delete[]pdf;
    delete[]psi;
}
fout.close();

return 0;
}
