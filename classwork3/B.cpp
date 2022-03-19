#include<iostream>
using namespace std;

int BinSearch(int *a, int N, int x){
    int L = 0;
    int R = N - 1;

    while (L <= R){

        int m = (L + R)/2;

        if (a[m] < x){
            L = m + 1;
        }
        else if (a[m] > x){
            R = m - 1;
        }
        else{
            return m;
        }
    }
    return -1;
    }

int main(){

int N;
int x;
int array[200]; //мы не знаем динамические массивы

cin >> N;
cin >> x;
for (int i = 0; i < N; i++){
    cin >> array[i];
}

cout << BinSearch(array, N, x);


return 0;
}
