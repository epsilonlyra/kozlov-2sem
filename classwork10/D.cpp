#include<iostream>
#define INF 100

void qsort (int *arr, int N){
int i = 0;
int j = N - 1;
int pivotval = arr[N / 2];

while (i <= j){
    while (arr[i] < pivotval){
        i++;
    }

    while (arr[j] > pivotval){
        j--;
    }

    if (i <= j){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}

if (j > 0){
    qsort(arr, j + 1);
}

if (i < N){
    qsort(&arr[i], N - i);
}

}

int main(){

int N, M;

std :: cin >> N;

std :: cin >> M;

int** Cost = new int* [M + 3];

for (int i = 0; i < M + 3; i++){
    Cost[i] = new int[M + 3];
}

int* Marks = new int [M + 2];

Marks[0] = 0;

for(int i = 1 ; i <= M ; i++){
  std :: cin >> Marks[i];
}

M++; // мда треш ЭТО ОЧЕНЬ ВАЖНО!!!!!!

Marks[M] = N;

qsort(Marks, M + 1);


for(int i = 0; i <= M; i++){
    Cost[i][i] = Cost[i][i + 1] = 0;
}

for(int m = 2; m <= M ; m++){
    for(int i = 0 ; i + m <= M ; i++){

         int L = Marks[i + m] - Marks[i];
         Cost[i][i + m] = INF;

         for(int j = 1 ; j < m; j++)
            if(Cost[i][i + m] > Cost[i][i + j] + Cost[i + j][i + m]){
               Cost[i][i + m] = Cost[i][i + j] + Cost[i + j][i + m];
            }
         Cost[i][i + m] += L;
    }
}

std :: cout << Cost[0][M];

delete []  Marks;

for (int i = 0; i < M + 2; i++){
		delete [] Cost[i]
	
}

delete [] Cost;

return 0;
}
