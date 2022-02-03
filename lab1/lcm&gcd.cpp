#include <iostream>
using namespace std;

int GCD(int x, int y) {
    int a = x;
    int b = y;
    if (a < b) {
    int temp = a;
    a = b;
    b = temp;
    }
    int  r1 = 1;
    while (r1 != 0) {
        r1 = a % b;
        a = b;
        b = r1;
    }
    return(a);
    }

int LCM(int x, int y){
    return(x*y / GCD(x, y));
}

int main() {
int a = 1, b = 1;
cin >>a>>b;
cout << GCD(a, b)<<endl;
cout<<LCM(a,b)<<endl;

return(0);
}
