#include<iostream>
using namespace std;
bool issimple(long int N){
    bool simple = true;
    for (long int i = 2;i * i <= N; i++){
        if ((N%i == 0) || (N == 4)){
            simple = false;
            break;
        }
    }
    return(simple);
}
int main(){
long int n;
cin>>n;
if (issimple(n)){
    cout<<n;
    }
else{
    for(long int i = n-2; i * i >= n; i--){
        if((n % (n - i) == 0) && (issimple(n-i))) {
            cout << (n - i)<<" ";
        }
    }
}
return(0);
}
