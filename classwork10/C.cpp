#include<iostream>

int main(){
int N;
std :: cin >> N;

int* seq = new int [N];

for (int i = 0; i < N; i++){
    std :: cin >> seq[i];
}


int* increase_seq = new int [N];

for (int i = 0; i < N; i++) increase_seq[i] = 0;

for (int i = 0; i < N; i++){
    int length_of_max = 0;

    for (int j = 0; j < i; j++){
        if (seq[j] < seq[i]){
            if (length_of_max < increase_seq[j]){
                length_of_max = increase_seq[j];
            }
        }
    }

    increase_seq[i] = length_of_max + 1;
}

int max_length = 0;

for (int i = 0; i < N; i++){
    if (increase_seq[i] > max_length){
        max_length = increase_seq[i];
    }
}

std :: cout << max_length;

delete []  increase_seq;
delete [] seq;

return 0;
}
