#include<iostream>
using namespace std;
enum Reaction {alpha =  -2, betaplus = -1, betaminus = 1};
struct Atom{
    char name [2];
    int A = 0;
    int Z = 0;

    friend istream& operator>>(istream &input, Atom &other) {
        input >> other.name >> other.A >> other.Z;
        return input;
    }

    friend ostream& operator>>(ostream &input, Atom &other) {
        input << other.name << other.A << other.Z;
        return input;
    }

    bool operator<(Atom &other){
        return(Z < other.Z);
    }

};

void qsort (Atom *arr, int N){

    int i = 0;
    int j = N - 1;
    Atom pivotval = arr[N / 2];

    while (i <= j){
        while (arr[i] < pivotval){
            i++;
        }

        while (pivotval < arr[j]){
            j--;
        }

        if (i <= j){
            Atom temp = arr[j];
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

int BinSearch(Atom *a, int N, int x){
    int L = 0;
    int R = N - 1;

    while (L <= R){

        int m = (L + R)/2;

        if (a[m].Z < x){
            L = m + 1;
        }
        else if (x < a[m].Z){
            R = m - 1;
        }
        else{
            return m;
        }
    }
    return -1;
    }

struct React{
    char name[2];
    Reaction reaction;


    React() {}

    React(char *t_name, char *t_deckay){

        for(int i = 0; i < 2; i ++) {
            name[i] = '\0';
        }
        for(int i = 0; *(t_name + i) != '\0'; ++i) {
            name[i] = *(t_name + i);
        }

        char lastletter;
        for(int i = 0; *(t_deckay + i) != '\0'; ++i) {

            lastletter = *(t_deckay + i);
        }

        if (lastletter == '+'){
            reaction = betaplus;
        }
        if (lastletter == '-'){
            reaction = betaminus;
        }
        if (lastletter == 'a'){
            reaction = alpha;
        }
    }
};

bool AreEqual (char *a, char *b){

    for (int i = 0; i < 2; i++){
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}
int main(){
int N;

cin >> N;

Atom *AtomList = new Atom [N];
for (int i = 0; i < N; i++){
    cin >> AtomList[i];
}

qsort(AtomList, N);

int M;
cin >> M;

React *ReactList = new React [M];

for (int i = 0; i < M; i++){
    char t_name[2];
    char t_deckay[20];
    cin >> t_name;
    cin >> t_deckay;
    ReactList[i] = React(t_name, t_deckay);
}

int *NuclearCharge = new int [M];
for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){ // я понимаю что это мега неэффективно и медленно но нет времени думать
        if (AreEqual(ReactList[i].name, AtomList[j].name)){
            NuclearCharge[i] = AtomList[j].Z +  ReactList[i].reaction;
            break;
        }
    }
}

for (int i = 0; i < M; i++){
    int temp = BinSearch(AtomList, N, NuclearCharge[i]);
    if (temp == -1){
        cout << "NO DATA"<<" ";
    }
    else{
        for (int j = 0; j < 2; j++){
            cout << (AtomList[temp]).name[j];
        }
        cout <<" ";
    }
}

return 0;
}
