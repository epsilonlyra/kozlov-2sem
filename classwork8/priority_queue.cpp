#include <iostream>
#include <queue>

struct Node{

    Node* left;
    Node* right;
    Node* father;
    int field;

    Node(int data){
        left = nullptr;
        right = nullptr;
        father = nullptr;
        field = data;
    }

    Node(){
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

    Pyramid(int value){
        head = new Node(value);
    }

    void UpHeap(Node* sus){

        if (sus->father == nullptr){
            return;
        }

        if (sus->father->field < sus->field){

            int change = sus->father->field;
            sus->father->field = sus->field;
            sus->field = change;

            UpHeap(sus->father);
        }
    }

    void add(int value){
        Node* tmp = new Node(value);

        if (head == nullptr){
            head = tmp;
            return;
        }

        Node* lfather = lastfather(head);
        tmp->father = lfather;

        if (lfather->left == nullptr){
            lfather->left = tmp;
        }

        else{
            lfather->right = tmp;
        }
        UpHeap(tmp);
    }

    void print(){
        if (head == nullptr){
            std :: cout << '\n';
            return;
        }

        Queue imposter(head);
        while (!imposter.is_empty()){
            Node* tmp = imposter.front();
            std :: cout << tmp->field << " ";
            imposter.pop();

            if (tmp->left != nullptr){
                imposter.push(tmp->left);
            }
            if (tmp->right != nullptr){
                imposter.push(tmp->right);
            }
        }
        std :: cout << '\n';
    }

    void pop(){


        if (head == nullptr){
            return;
        }

        Node* sadfather = lastfather(head);
        if (sadfather->right != nullptr){
            delete sadfather->right;
            sadfather->right = nullptr;
        }
        else{
            if (sadfather == head){
                delete head;
                head = nullptr;
                return;
            }
            delete sadfather->left;
            sadfather->left = nullptr;
        }
    }

};


int main(){
Pyramid A(10);
A.add(20);
A.add(40);
A.add(5);
A.print();
A.pop();
A.print();
return 0;
}
