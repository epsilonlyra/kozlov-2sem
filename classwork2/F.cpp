#include<iostream>
using namespace std;
int main(){
int N;
bool temp = true;
cin >> N;
for (int i = 2;i * i <= N; i++){
    if ((N%i == 0) || (N == 4)){
        temp = false;
        break;
        }
    }

if (temp){
    cout << "YES";
}
else{
    cout << "NO";
}

return(0);
}
