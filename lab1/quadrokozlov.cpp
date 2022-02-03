#include <iostream>
#include <cmath>
using namespace std;

int main(){
double a = 0,b = 0,c = 0;
double  D = 0, x1 = 0, x2 = 0;
cin >>a>>b>>c;
if (a != 0) {
	D = b*b - 4*a*c;
	if (D < 0) {
		cout <<"";
	}
	else if (D == 0) {
		cout << -1 * b / (2*a);
	}
	else {
		x1 = (-b + sqrt(D))/(2*a);
		x2 = (-b - sqrt(D))/(2*a);
		double sub = 0;
		if (x2 < x1) {
			sub = x2;
			x2 = x1;
			x1 = sub;
		}
		cout <<x1<<" "<<x2;
	}
}
else {
	if (b == 0) {
		if (c == 0) {
			cout<<"Any number";
		}
		else {
			cout<<"";
		}
	}
	else {
		cout<< -c/b;
	}
}
return (0);
}
