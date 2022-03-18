#include<iostream>
using namespace std;

void order(int &x, int &y){
    if (y < x){
        int temp = x;
        x = y;
        y = temp;
    }
}

struct section{
    int x = 0, y = 0;

    friend istream& operator>>(istream &input, section &other) {
        input >> other.x >> other.y;
        return input;
    }

    section operator+(const section right){
        section sum;
        int x_sum, y_sum;
        if ((right.x > y) || (right.y <  x)){
            // магические числа, такие что у отрезка конец меньше начала
            x_sum = 0;
            y_sum = -1;
        }
        if (right.y >= y){
            y_sum = y;
        }
        else{
            y_sum = right.y;
        }
        if (right.x >= x){
            x_sum = right.x;
        }
        else{
            x_sum = x;
        }
    sum = {x_sum, y_sum};
    return(sum);
    }
};

int Check(section* Keys, int N){
    if (N == 1){
    return 1;
    }
    else{
        Keys[0] = Keys[0] + Keys[N - 1];
        if (Keys[0].x > Keys[0].y){
            return 0;
        }
        else{
            return(Check(Keys, N - 1));
        }
    }
}

int main(){
int N;
cin >> N;

section* Keys = new section[N];

for (int i = 0; i < N;i++){
    cin >> Keys[i];
    order(Keys[i].x, Keys[i].y);
}

if (Check(Keys, N) == 1){
    cout << "YES";
}
else{
    cout << "NO";
}

cout << endl;

return 0;
}
