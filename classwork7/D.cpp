#include<iostream>
using namespace std;
struct Street{

    int x1,y1,x2,y2;

    friend istream& operator>>(istream &input, Street &other) {
        input >> other.x1 >> other.y1 >> other.x2 >> other.y2;
        return input;
    }
};

struct Vector{

    int x, y;

    int operator*(const Vector &other){
        return(x * other.y - y * other.x);
    }
};

void order(int &x, int &y){
    if (y < x){
        int temp = x;
        x = y;
        y = temp;
    }
}

void Intersect (Street& alpha, Street& beta){

        Vector a = {alpha.x2 - alpha.x1, alpha.y2 - alpha.y1};

        Vector one = {beta.x1 - alpha.x1, beta.y1 - alpha.y1};

        Vector two = {beta.x2 - alpha.x1, beta.y2 - alpha.y1};

        int cross_product = (a * one) * (a * two);

        if (cross_product ==  0){
            order(alpha.x1, alpha.x2);
            order(beta.x1, beta.x2);

            order(alpha.y1, alpha.y2);
            order(beta.y1, beta.y2);

            if  ((alpha.x2 != 0) && (alpha.x1 != 0)){
                if  (((alpha.x2 <= beta.x2) && (alpha.x2 >= beta.x1)) || ((alpha.x1 >= beta.x1) && (alpha.x1 <= beta.x2))){
                    cout << "NO";
                }
                else{
                    cout << "YES";
                }
            }
            else{
                if  (((alpha.y2 <= beta.y2) && (alpha.y2 >= beta.y1)) || ((alpha.y1 >= beta.y1) && (alpha.y1 <= beta.y2))){
                    cout << "NO";
                }
                else{
                    cout << "YES";
                }
            }
        }
        else{
            if (cross_product > 0){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
}
int main(){

Street alpha, beta;

cin >> alpha >> beta;
Intersect(alpha, beta);
cout << endl;
return 0;
}
