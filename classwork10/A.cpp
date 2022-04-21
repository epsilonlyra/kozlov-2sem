#include<iostream>



int main(){

int N;
std :: cin >> N;
int Stages[4];
Stages[0] = -1; // просто для удобства нумерации
Stages[1] = 1;
Stages [2] = 2;
Stages[3] = 4;


for (int i = 3; i < N; i ++ ){
    int temp = Stages[3];
    Stages[3] = Stages[1] + Stages[2] + Stages[3];
    Stages[1] = Stages[2];
    Stages[2] = temp;
}

if (N <= 3){
    std :: cout << Stages[N];
}

else{
    std :: cout << Stages[3];
}

std :: cout << '\n';


return 0;
}
