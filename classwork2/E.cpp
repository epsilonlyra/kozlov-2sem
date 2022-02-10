#include<iostream>
using namespace std;
int main(){
int a = 1;
int maxim = 0;
int sum = 1;
cin >> maxim;
while (a != 0){
    cin >> a;
    if (a > maxim) {
    maxim = a;
    sum = 1;
    }
    else if (a == maxim){
    sum += 1;
    }
}
    cout<<sum<<endl;
return(0);
}
