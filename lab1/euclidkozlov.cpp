#include <iostream>
using namespace std;
int main() {
int a = 1, b = 1;
int temp = 0;
cin >>a>>b;
if (a < b) {
    temp = a;
    a = b;
    b = temp;
}
int  r1 = 1;
while (r1 != 0) {
	r1 = a % b;
	a = b;
	b = r1;
}
cout << a;

return(0);
}
