#include <iostream>
using namespace std;

int tenpower(int x){
    int power = 1;
    for (int k = 1; k <= x;k++ ){
        power *= 10;
    }
    return(power);
}
int digit(int i, int A, int N){
    int digit = 0;
    for (int k = 1; k<i; k++){
        A = A%tenpower(N-k);
    }
    return(A/tenpower(N - i));
}

int main(){
int N;
int A;
bool polyndrom = false;
cin >> N;
cin >> A;

for (int i = 1; i <= N; i++){
        if (digit(N-i+1, A, N) != digit(i, A, N)){
            break;
        }
        polyndrom = true;
}
if (!polyndrom){
    for (int i = 1; i <= N; i++){
        cout<<digit(N-i+1, A, N);
    }
}
else{
    cout<<1;
}
return(0);
}
