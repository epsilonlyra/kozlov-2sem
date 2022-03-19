#include<iostream>
using namespace std;
void swapm(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void gnomeSort(int *a, int size){
    int i = 1;
    int j = 2;
    while (i < size){
        if (a[i - 1] > a[i]){
            i = j;
            j += 1;
        }

        else{
            swapm(&a[i - 1], &a[i]);
            i -= 1;

            if (i == 0){
                i = j;
                j += 1;
            }
        }
    }
}

int main(){

int N;
int array[200]; //мы не знаем динамические массивы

cin >> N;
for (int i = 0; i < N; i++){
    cin >> array[i];
}

gnomeSort(array, N);

for (int i = 0; i < N; i++){
    cout << array[i];
}

return 0;
}
