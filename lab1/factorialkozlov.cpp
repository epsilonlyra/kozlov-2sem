#include <iostream>
using namespace std;
int main(){
unsigned long int n = 1, m = 1;
cin >> n;
while (n > 1){
    m = m * n;
    n -= 1;
}
cout << m;
return (0);
}
