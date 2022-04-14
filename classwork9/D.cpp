#include <iostream>
/*
Программа расчитана на положительные дроби меньшие единицы
в некоторых случаях из-за достаточного глупого метода может не сработать
потому что знаменатели переполняются и становятся больше чем даже long long
*/
struct denom_array_t{
    unsigned long long * arr;
    int sz;
    int capacity;

    denom_array_t(){
        arr = nullptr;
        sz = 0;
        capacity = 0;
    }

    denom_array_t(unsigned long long  den){
        arr = new unsigned long long [10];
        arr[0] = den;
        sz = 1;
        capacity = 10;
    }

     denom_array_t append(unsigned long long  den){
        if (sz == 0){
            denom_array_t tmp (den);
            *this = tmp;
            return *this;
        }

        if (sz == capacity){
            unsigned long long * tmp = new unsigned long long [capacity * 2];
            for (int i = 0; i < sz; i++){
                tmp[i] = arr[i];
            }
            tmp[sz] = den;
            delete [] arr;
            arr = tmp;
            capacity = capacity * 2;
        }
        else{
            arr[sz] = den;
        }
        sz++;
        return *this;
    }

    void delet(){
        delete [] arr;
        arr = nullptr;
        sz = 0;
        capacity = 0;
    }
};


denom_array_t egyptian_fractions(unsigned long long  num, unsigned long long  den){
    if (num == 0){
        denom_array_t res;
        return res;
    }
    if (num == 1){
        denom_array_t res(den);
        return res;
    }
    if (den >=  1000000000000){
        std :: cout << "Error, Denominator too Big " << '\n';
        denom_array_t res;
        return res;
    }


    unsigned long  long possible_den = 2;
    bool found = false;
    long  long x;
    while (!found){
         x =  num * possible_den - den;

        if (x >= 0){
            break;
        }

        possible_den++;
    }

    return  (egyptian_fractions(x, possible_den * den)).append(possible_den);
}

int main(){
denom_array_t caesar;
int num, den;
std :: cin >> num >>  den;
caesar = egyptian_fractions(num, den);

for (int i = 0; i < caesar.sz; i++){
    std :: cout << caesar.arr[i] << " ";
}

caesar.delet();
return 0;
}
