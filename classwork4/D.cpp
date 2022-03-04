#include<iostream>
using namespace std;
void qsort (int *arr, int N){
int i = 0;
int j = N - 1;
int pivotval = arr[N / 2];

while (i <= j){
    while (arr[i] < pivotval){
        i++;
    }

    while (arr[j] > pivotval){
        j--;
    }

    if (i <= j){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}

if (j > 0){
    qsort(arr, j + 1);
}

if (i < N){
    qsort(&arr[i], N - i);
}

}

int main(){
int N, *arr;
cin >> N;
arr = new int[N];

for (int i = 0; i < N; i++){
    cin>>arr[i];
}
qsort(arr, N);

for (int i = 0; i < N; i++){
    cout<<arr[i]<< " ";
}





return(0);
}
