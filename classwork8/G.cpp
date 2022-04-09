#include <iostream>
/*
эта штука работает только если во ВСЕХ операциях ставить скобки

все односимвольное без пробелов

*/
struct Node{

    Node* left;
    Node* right;
    Node* father;
    int field;
    char sign;

    Node(int data, char sign){
        left = nullptr;
        right = nullptr;
        father = nullptr;
        field = data;
        sign = sign;
    }

    Node(){
        left = nullptr;
        right = nullptr;
        father = nullptr;
    }

};

struct QNode{

    Node* field;
    QNode* next;
    QNode*prev;
};

struct Queue{

    QNode* head;
    QNode* tail;


    Queue(Node* value){

        head = new QNode;
        head->field = value;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }

    bool is_empty(){
        return (tail == nullptr);
    }


    void push(Node* value){
        QNode* tmp = new QNode;
        tmp->field = value;
        tmp->prev = nullptr;
        tmp->next = tail;
        if (tail != nullptr){
            tail->prev = tmp;
        }
        else{
            head = tmp;
        }
        tail = tmp;
    }

    void pop(){
        if (!is_empty()){

            if (head->prev == nullptr){
                delete tail;
                tail = nullptr;
                head = nullptr;
            }
            else{
                head = head->prev;
                delete head->next;
                head->next = nullptr;
            }
        }
    }



    Node* front(){
        if (head != nullptr){
            return head->field;
        }
        else{
            return nullptr;\
        }
    }

};


Node* lastfather(Node* root){
    Queue imposter(root);
    Node* tmp;

    while (!imposter.is_empty()){
        tmp = imposter.front();
        imposter.pop();

        if (tmp->left != nullptr && tmp->right != nullptr){
            imposter.push(tmp->left);
            imposter.push(tmp->right);
        }
        else{
            break;
        }
    }

    while (!imposter.is_empty()){
        imposter.pop();
    }

    return tmp;

}

struct Pyramid{
    Node* head;

    Pyramid(int value, char sign){
        head = new Node(value, sign);
    }

    Pyramid(){
        head = new Node;
    }

    void Adoption(Node* father, Node* son, char place){
        son->father = father;

        if (place == 'r'){
            father->right = son;
        }
        if (place == 'l'){
            father->left = son;
        }

        if (head == nullptr){
            std :: cout << '\n';
            return;
        }
    }

};

int eval(Node* root){
    if (root->sign == 'f'){
        return root->field;
    }
    else{
        if (root->sign == '*'){
            return eval(root->left) * eval(root->right);
        }

        if (root->sign == '+'){
            return eval(root->left) + eval(root->right);
        }

        if (root->sign == '-'){
            return eval(root->left) - eval(root->right);
        }

        if (root->sign == '/'){
            return eval(root->left) / eval(root->right);
        }
    }
}


int main(){

Pyramid Expression;

Node* current = Expression.head;

// создаем левую скобку
Node* son = new Node;

Expression.Adoption(current, son, 'l');
current = son;

char k ='f';


while (k != '\n'){

     k = std :: cin.get();

    if (k == '('){
        Node* son = new Node;
        Expression.Adoption(current, son, 'l');
        current = son;
    }

    else if (k == '+'|| k == '-' || k == '*' || k == '/' ){
        current->sign = k;
        Node* son = new Node;
        Expression.Adoption(current, son, 'r');
        current = son;
    }

    else if (k == ')'){
        current = current->father;
    }

    else if (k != '\n'){
        int a = k -'0';
        current->sign = 'f';
        current->field = a;

        current = current->father;
    }

    else if (k == '\n'){
        current = current->father;
    }
}

std :: cout << eval(Expression.head);
return 0;
}
