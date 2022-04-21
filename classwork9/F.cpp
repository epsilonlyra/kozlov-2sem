#include<iostream>
/*
алгоритм меганеэффективный
O(N^6) ??
*/
bool  is_in_array(int* array , int size, int x){
    for (int i = 0; i < size; i++){
        if ((array[i]) == x){
            return true;
        }
    }
    return false;
}

int conjugate_line_number(int** Incedent, int N, int M, int current_line, int j){
    for (int k = 0; k < N; k++){
        if ((Incedent[k][j] != 0 ) &&(k != current_line)){
            return k;
        }
    }
    std :: cout << "error" << '\n';
    return -1;
}


int find_min_index(int ** Incedent, int N, int M, int current_line, int* forbiden, int forbiden_size ){

    int minval = 1000; // большое число
    int min;
    bool ok = false;

    for (int j = 0; j < M; j++){
        int line_of_double = conjugate_line_number(Incedent, N, M, current_line, j);

        if (!is_in_array(forbiden, forbiden_size, line_of_double )){
            if ((Incedent[current_line][j] < minval)  && (Incedent[current_line][j] != 0)){
                ok = true;
                minval = Incedent[current_line][j];
                min = j;
            }
        }
    }

    if (ok){
        return min;
    }
    else{
        return -2; // индикатор что в данной строке такого числа нет
    }
}

int main(){

int N; // сколько сел
int M; // сколько дорог

std :: cin >> M >> N;

int** Incident = new int* [N];

for (int i = 0; i < N; i++){
    Incident[i] = new int [M];
}

for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
        std :: cin >> Incident[i][j];
    }
}


int places_connected = 1;

int* connected_places  = new int [N];
connected_places[0] = 0;

int way = 0;
while (places_connected < N){


    int j = -2;
    int length = 1000; // большое число
    int chosen_place = 0;

    for (int amogus = 0; amogus < places_connected; amogus++){

        int place = connected_places[amogus];

        int current_j_min = find_min_index(Incident, N, M, place, connected_places, places_connected);
        int current_length;

        if (current_j_min == -2){
            current_length = 1000; // большое число
        }
        else{
            current_length = Incident[place][current_j_min];

        }

        if (current_length < length){
            j = current_j_min;
            length = current_length;
            chosen_place = place;
        }
    }

    for (int i = 0; i < N; i++){
        if ((Incident[i][j] != 0 )&& (i != chosen_place)){
            connected_places[places_connected] = i;
            places_connected++;
            way += length;

            break;
        }
    }
}

std :: cout << way * 98 << '\n';

for (int i = 0; i < N; i++){
    delete [] Incident[i];
}
delete [] Incident;
return 0;
}
