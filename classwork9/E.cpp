#include<iostream>




int main(){
int K;
std :: cin >> K;

int** Congtiguity = new int* [K];
for (int i = 0; i < K; i++){
    Congtiguity[i] = new int [K];
}

for (int i = 0; i < K; i++){
    for (int j = 0; j < K; j++){
        std :: cin >> Congtiguity[i][j];
    }
}


int N = K; // количество вершин
int M = 0; // количество граней
int a = 0; // самосопряженные вершины
int b = 0; // остальные

for (int i = 0; i < K; i++){
    for (int j = 0; j < K; j++){
        if (Congtiguity[i][j] != 0){
            if (i == j){
                a++;
            }
            else{
                b++;
            }
        }
    }
}

M = a + b/2;

int** Incident = new int* [N];
for (int i = 0; i < N; i++){
    Incident[i] = new int [M];
}

for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
        Incident[i][j] = 0;
    }
}

int k  = 0;
for (int i = 0; i < K; i++){
    for (int j = 0; j <= i; j++){
        if (Congtiguity[i][j] != 0){
            Incident[j][k] = Congtiguity[i][j];
            Incident[i][k] = Congtiguity[i][j];
            k++;
        }
    }
}

for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
        std :: cout << Incident[i][j]<<" ";
    }
    std :: cout <<'\n';
}
std :: cout << '\n';
for (int i = 0; i < K;i++){
    delete [] Congtiguity[i];
}

delete [] Congtiguity;

for (int i = 0; i < N; i++){
    delete [] Incident[i];
}

delete [] Incident;

return 0;
}
