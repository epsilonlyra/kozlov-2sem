#include<iostream>
using namespace std;
int main(){
int a = 1;
int maxim = 0;
cin >> maxim;
while (a != 0){
    cin >> a;
    if ((a%2 == 0)&&(a > maxim)) {
    maxim = a;
    }
}
if (maxim%2 == 0){
    cout<<maxim<<endl;
}
else{
cout<<endl;
}
return(0);
}
