#include<iostream>
using namespace std;
int main() {
int N = 0;
cin>>N;
while (N != 1){
    if ((N%2 != 0)) {
        break;
    }
    N = N / 2;
}
if  (N == 1){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
    }


return(0);
}
