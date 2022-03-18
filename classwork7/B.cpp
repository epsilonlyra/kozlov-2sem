#include<iostream>
using namespace std;
struct student{
    char name[20];
    int mark;

    bool operator<(const student right) {
        if (mark != right.mark){
            return mark <  right.mark;
            }

        else{
            for (int i = 0;  i < 20; i++){
                if (name[i] < right.name[i]){
                    return true;
                }
                if (name[i] > right.name[i]){
                    return false;
                }
            }
            return false;
        }
    }

};

void qsort (student *arr, int N){

    int i = 0;
    int j = N - 1;
    student  pivotval = arr[N / 2];

    while (i <= j){
        while (arr[i] < pivotval){
            i++;
        }

        while (pivotval < arr[j]){
            j--;
        }

        if (i <= j){
            student temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }

    if (j > 0){
        qsort(arr, j + 1);
    }

    if (i < N){
        qsort(&arr[i], N - i);
    }

}

int main() {

int  N; //количество студентов
cin >> N;
student* Class = new student[N];

for (int i = 0; i < N; i++){
    cin >> Class[i].name;
    cin >> Class[i].mark;
}

qsort(Class, N);

int M; // проходные
cin >> M;

for (int i = 0; i < N; i++){
    if (Class[i].mark > M){
        cout << (Class[i].name) << " ";
    }
}

cout << endl;
return 0;
}
