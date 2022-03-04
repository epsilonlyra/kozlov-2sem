#include<iostream>
using namespace std;

int counter(){
static int iwascalled = 0;

iwascalled++;

return(iwascalled);
}

int main(){
int N;
cin >> N;

for (int i = 0; i < N-1; i++){
    counter();
}

cout<<counter();

return(0);
}
