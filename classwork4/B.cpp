#include<iostream>
using namespace std;
int main(){

int *arr, N, temp;
cin >> N;
arr = new int[N];

for (int i = 0; i < N; i++){
    cin>>arr[i];
}

for (int i = 0; i < N; i++){
    cout<<*(arr + i)<<" ";
}

cout<<endl;

for (int i = 0; i < N; i++){
    cout<<*(arr + N - 1 - i)<<" ";
}

return(0);
}
