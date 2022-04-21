#include <iostream>

int main(){
int N;
std :: cin >> N;

int* Steps = new int [N + 1];

Steps[0] = -1; //для того чтобы нумерация с единицы

for (int i = 1; i < N + 1; i++){
    std :: cin >> Steps[i];
}

int *Evolve_cost = new int [3 + 1];
Evolve_cost[0] = -1; // для того чтобы нумерация была с единицы
Evolve_cost[1] = Steps[1];
Evolve_cost[2] = Steps[2];
Evolve_cost[3] = Steps[3];

for (int i = 4; i <= N; i++){
    int tmp = Evolve_cost[3];
    Evolve_cost[3] = std :: min(Evolve_cost[1], std :: min(Evolve_cost[2], Evolve_cost[3])) + Steps[i];
    Evolve_cost[1] = Evolve_cost[2];
    Evolve_cost[2] = Evolve_cost[3];
}

std :: cout << Evolve_cost[3];

return 0;
}
