#include <iostream>



int main(){
int N;
int M;
int K;
std :: cin >> N >> M >> K;

int* gas_stations = new int[K];


for (int i = 0; i < K; i++){
    std :: cin >> gas_stations[i];
}


int gas_stations_visited = 0;

int coordinate = 0;
int next_gas_station = 0;
bool death = false;

while (coordinate < N - M){

    if (gas_stations[next_gas_station] - M - coordinate > 0){
        death = true;
        break;
   }
   int i;
   for (i = next_gas_station; i < K; i++){
        int x = gas_stations[i] - M - coordinate;

        if (x > 0){
            break;
        }
   }
   coordinate = gas_stations[i - 1];
   next_gas_station = i;
   gas_stations_visited++;

}


if (death){
    std :: cout <<-1;
}
else{
    std :: cout << gas_stations_visited;
}
std :: cout << '\n';

delete [] gas_stations;
return 0;
}
