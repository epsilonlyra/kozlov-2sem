#include<iostream>
using namespace std;
int main(){
int a = 1;
int sus = 0;
while (a != 0){
    cin >> a;
    if ((a%2 == 0)&&(a != 0)) {
    sus += 1;
    }
}
cout<<sus<<endl;

return(0);
}
