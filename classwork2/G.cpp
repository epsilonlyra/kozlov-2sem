#include<iostream>
using namespace std;
int main(){
int N;
bool temp = true;
cin >>N;
for (int i = 2;i * i <= N; i++){
    if (N%i == 0){
        cout<<(i)<<endl;
        }
    }
for (int i = N;i * i >= N; i--){
    if (N%i == 0){
        cout<<N/(i)<<endl;
        }
    }
return(0);
}
