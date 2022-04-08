#include <iostream>

struct Node{

int number;
Node* next;

};

struct Stack{

Node* head;

Stack(){

    head = nullptr;
}

void push(int number){
    if (head == nullptr){
        head = new Node;
        head->next = nullptr;
        head->number = number;
    }
    else{
        Node* tmp = new Node;
        tmp->next = head;
        tmp->number = number;
        head = tmp;
    }
}

Node* Head(){
    return (head);
}

Node*  pop(){
    Node* result = head;
    if (head != nullptr){
        if (head->next != nullptr){
            Node* tmp = head->next;
            head = tmp;
        }
        else{
            head = nullptr;
        }
    }
    return result;
}

bool is_empty(){
    return (head == nullptr);

}

};

bool is_sign(char k){
    return ((k == '+')||(k == '-')||(k == '*')||(k == '/'));
}

int main(){

Stack Equation;

char k = 'f';

bool correct = true;
while (k != '\n'){
    k = std :: cin.get();

    if (is_sign(k)){
        Node* right_operand = Equation.pop();
        Node* left_operand = Equation.pop();

        if ((left_operand == nullptr)|| (right_operand == nullptr)){
            correct = false;
            break;
        }

        int left = left_operand->number;
        int right = right_operand->number;

        if (k == '*'){

            Equation.push(left * right);
        }
        if (k == '+'){
            Equation.push(left + right);
        }
        if (k == '/'){
            if (right == 0){
                correct = false;
                break;
            }
            Equation.push(left / right);
        }
        if (k == '-'){
            Equation.push(left - right);
        }

    delete right_operand;
    delete left_operand;
    }

    else if (k != '\n'){
        int digit = k - '0';
        Equation.push(digit);
    }
}

if (correct){
std :: cout << Equation.Head()->number << std :: endl;
}

else{
    std :: cout <<"Incorrect Equation" <<  std :: endl;
}

delete Equation.Head();


return 0;
}
