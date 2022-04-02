#include<iostream>

struct Node{

    int field;
    Node* next;
};

struct List{

	Node* head;

	List (int value) {
		head = new Node;
		head->next = nullptr;
		head->field = value;
	}

	void print (){
		Node* current = head;
        if (current != nullptr){
            while (current->next != nullptr){
                std :: cout << current->field << " ";
                current = current->next;
            }
            std :: cout << current->field <<" ";
        }
        else{
            std :: cout << " ";
        }

        std :: cout << std :: endl;
	}

	void append(int value){

        Node* tmp = new Node;
        tmp->next = nullptr;
        tmp->field = value;

        Node* current = head;

        if (current == nullptr){
            head = tmp;
        }

        else {
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = tmp;
        }
    }
};

void reverse(List* list){
    if (list->head->next != nullptr){
        Node* current = list->head->next;
        Node* future  = current->next;
        list->head->next = nullptr;

        while (future != nullptr){
            current->next = list->head;
            list->head = current;
            current = future;
            future = future->next;
        }
        current->next = list->head;
        list->head = current;
    }
}


int main(){
List A(0);
for (int i = 1; i < 2; i++){
    A.append(i);
}

A.print();
reverse(&A);
A.print();


return 0;
}
