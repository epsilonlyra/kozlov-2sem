#include<iostream>
using namespace std;

struct Node {
    int field;
    Node* next;
};

void append(Node** head_ptr, int value){
    Node* current = *head_ptr;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node* tmp = new Node;
    tmp->next = nullptr;
    tmp->field = value;
    current->next = tmp;
}

void add(Node** head_ptr,int value, int index){

    if (index == 0){
        (**head_ptr).field = value;
    }
    else{
        int i = -1;

        Node* current = *head_ptr;
        Node* prev = nullptr;

        while (current!= nullptr){
            i++;
            if (i == index){

                break;
            }
            prev = current;
            current = current->next;

        }

        Node *tmp = new Node;
        tmp->field = value;
        prev->next = tmp;
        tmp->next = current;
    }

}

void print_nodes(Node* head_ptr){
    Node* current = head_ptr;
    cout << current->field << " ";

    while (current->next != nullptr){
        current = current->next;
        cout << current->field << " ";
    }
    cout << endl;
}

void pop(Node** head_ptr){
    Node* current = *head_ptr;

    while (current->next->next != nullptr){
        current = current->next;
    }
    current->next = nullptr;
    delete current->next;
}

int main(){

Node* head = new Node;
head->field = 10;
head->next = nullptr;

print_nodes(head);
append(&head, 10);
append(&head, 15);
print_nodes(head);
pop(&head);
print_nodes(head);


return 0;
}
