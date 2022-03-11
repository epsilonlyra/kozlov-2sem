#include <iostream>;
using namespace std;

int CycleMean (int  *x, int size){


    for (int k = 2; k <= 2 * size; k *= 2){

        for (int j = 0; j < size; j += k){
            if ((j + k/2) < size){
                x[j] = x[j] + x[j + k / 2];
                }
            else{
                x[j] = x[j];
            }
        }
    }
    return x[0];
}

int main(){
int N;
cin >> N;
int *x = new int[N];
for (int i = 0; i < N; i ++){
    cin >> x[i];

}
cout << CycleMean(x, N);




return 0;
}
