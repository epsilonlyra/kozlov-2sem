#include<iostream>

int exchange(int* N, int value){
    int i = 0;
    while (*N >= 0){
        *N -= value;
        if (*N >= 0){
            i++;
        }
    }
    if (*N < 0){
        *N += value;
    }
    return i;
}

int main(){
int N;
std :: cin >> N;

std :: cout << exchange(&N, 98) + exchange(&N, 49) + exchange(&N, 7) + exchange(&N, 1);

return 0;
}
