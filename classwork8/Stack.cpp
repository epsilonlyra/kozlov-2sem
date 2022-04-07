#include <iostream>

struct Node{
    int field;
    Node* next;
};

struct Stack{
    Node* top = new Node;

    Stack(int field){
        top->next = nullptr;
        top->field = field;
    }

    void push(int field){
        if (top == nullptr){
            top = new Node;
            top->next = nullptr;
            top->field = field;
        }
        else{
			Node *tmp = new Node;
			tmp->field = field;
			tmp->next = top ;
			top = tmp;
		}
       
    }

    Node* pop(){

        if (top == nullptr){
            return nullptr;
        }

        else {
            Node* tmp = top;
            top = top->next;
            delete tmp;
            return tmp;
            }
    }

    Node*  Top(){
        return top;
    }

    bool is_empty(){
        return (top == nullptr);
    }
};

int main(){

Stack A(10);
A.push(20);
A.push(10);
std :: cout << A.pop() << std :: endl;
std :: cout << A.is_empty();
return 0;
}
