#include<iostream>

struct Class{
    int start;
    int finish;

    int length(){
        return (finish - start);
    }

    bool operator<(const Class right) {
            return (finish < right.finish);
        }

    friend std::istream& operator>>(std::istream &input, Class &other) {
        input >> other.start >> other.finish;
        return input;
    }
};

void qsort (Class *arr, int N){

    int i = 0;
    int j = N - 1;
    Class pivotval = arr[N / 2];

    while (i <= j){
        while (arr[i] < pivotval){
            i++;
        }

        while (pivotval < arr[j]){
            j--;
        }

        if (i <= j){
            Class temp = arr[j];
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


int main(){
int N;
std :: cin >> N;
Class* Lessons = new Class[N];

for (int i = 0; i < N; i++){
std :: cin >> Lessons[i];
}


int attended = 0;
int current_time = 0;
int i = 0;

while(i < N){
    if (current_time <= Lessons[i].start){
        current_time = Lessons[i].finish;
        attended++;
    }
    i++;
}
std :: cout << attended;
delete [] Lessons;
return 0;
}
