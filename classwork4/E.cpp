#include<iostream>
using namespace std;

void swapm(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void order(int *arr, int N, int i){

int leftdown = 2*i + 1;
int rightdown = 2*i + 2;
int largest = i;

if (leftdown < N){
    if (arr[leftdown] > arr[i]){
        largest = leftdown;
    }
}
if (rightdown < N){
    if (arr[rightdown] > arr[largest]){
        largest = rightdown;
    }
}

if (largest != i){
    swapm(&(arr[largest]), &(arr[i]));

    order(arr, N, largest);
}

}

void trisort(int *arr, int N){

for (int i = N/2 - 1;  i >= 0; i--){
    order(arr, N, i);
}

for (int i = N - 1; i >= 0; i--){
    swapm(&(arr[0]), &(arr[i]));

    order(arr, i, 0);
}

}

int main(){
int *arr, N;
cin >> N;
arr = new int[N];

for (int i = 0; i < N; i++){
    cin >> arr[i];
}
trisort(arr, N);

for (int i = 0; i < N; i++){
    cout << arr[i];
}

return(0);
}
