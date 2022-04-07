#include <iostream>

struct Node{
    char field;
    Node* next;
};

struct Stack{
    Node* top;

    Stack(char field){
        top = new Node;
        top->next = nullptr;
        top->field = field;
    }

    Stack(){
        top = nullptr;
    }

    void push(char field){
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
Stack Brackets;


while (true){
    char k = std :: cin.get();
    if (k == '\n'){
        break;
    }
    Brackets.push(k);
}

int sum = 0;
int result = 1;
while (!Brackets.is_empty()){

    if (Brackets.Top()->field == ')'){
        sum++;
    }
    else{
        sum--;
    }

    if (sum < 0){
        break;
        result = 0;
    }

    Brackets.pop();
}
if (sum != 0){
    result = 0;
}
std :: cout << sum << std :: endl;
std :: cout << result;
return 0;
}
