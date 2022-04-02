#include<iostream>

struct Node{
    char field;
    Node* next;
    Node*prev;

};

struct List{

	Node* head;
	Node* tail;


	List (char value) {
		head = new Node;
		head->next = nullptr;
		head->prev = nullptr;
		head->field = value;
		tail = head;
	}

    List(){
        head = nullptr;
        tail = nullptr;
    }

	void append(char value){

        if (tail != nullptr){
            Node* tmp = new Node;
            tmp->field = value;
            tmp->next = nullptr;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        else{
            tail = new Node;
            tail->next = nullptr;
            tail->prev = nullptr;
            tail->field = value;
            head = tail;
        }
	}


};


int main(){
int N;
std :: cin >> N;

List Seq;
char a;

for (int i = 0; i < N; i++){
    std :: cin >> a;
    Seq.append(a);
}

int i = 1;
int place = 1;

Node* left = Seq.head;
Node* right = Seq.tail;

while (true){

    if (left->field == '1'){
        place = i;
        break;
    }

    if (right->field == '0'){
        place = N - i + 2;
        break;
    }

    i++;
    left = left->next;
    right = right->prev;
}

std :: cout << place << '\n';
return 0;
}
