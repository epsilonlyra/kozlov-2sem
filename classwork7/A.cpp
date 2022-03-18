#include<iostream>
using namespace std;
struct student{
    char name[20];
    int mark;
};

int main() {

int const N = 10; //количество студентов
student* Class = new student[N];

for (int i = 0; i < N; i++){
    cin >> Class[i].name;
    cin >> Class[i].mark;
}

int M;
cin >> M;

for (int i = 0; i < N; i++){
    if (Class[i].mark > M){
        cout << (Class[i].name) << " ";
    }
}

cout << endl;

return 0;
}
