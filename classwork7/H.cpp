#include<iostream>
using namespace std;

struct complex{
    float x = 0;
    float y = 0;


    friend istream& operator>>(istream &input, complex &other) {
        input >> other.x >> other.y;
        return input;
    }

    friend ostream& operator<<(ostream &output, complex &other) {
        output << other.x << "+" << other.y <<"i";
        return output;
    }

    complex() {
    x = 0.0;
    y = 0.0;
    }

    complex(float _r, float _i): x(_r), y(_i){};
    complex(float _r): complex(_r, 0.0){};

    complex operator+(const complex &other){
        complex sum = {x + other.x, y + other.y };
        return sum;
    }

    complex operator-(const complex &other){
        complex sum = {x - other.x, y - other.y };
        return sum;
    }

    complex operator*(const complex  &other){
        complex mult = {x * other.x - y * other.y, y * other.x + x * other.y};
        return mult;
    }

    complex conj(const complex &other){
        complex revers = {other.x, -other.y};
        return revers;
    }

    complex operator/(const complex &other){
    complex res;
    res = (*this * (conj(other)) ) * complex(1/(other.x * other.x + other.y * other.y));
    return res;
    }

};

int main(){
complex a;
float b;
cin >> a >> b;
complex c = a * complex(b);
cout << c;
return 0;
}
