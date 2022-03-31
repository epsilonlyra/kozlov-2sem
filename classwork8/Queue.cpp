#include<iostream>

struct Node{

    int field;
    Node* next;
    Node*prev;
};

struct Queue{

    Node* head;
    Node* tail;


    Queue(int value){

        head = new Node;
        head->field = value;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }

    bool is_empty(){
        return (tail == nullptr);
    }

    void print(){ // просто для наглядности
        if (is_empty()){
            std :: cout <<  " ";
        }

        else{
            Node* current = tail;
            while (current->next != nullptr){
                std :: cout << current->field << " ";
                current = current->next;
            }
            std :: cout << current->field << " ";
        }

        std :: cout << std :: endl;
    }

    void push(int value){
        Node* tmp = new Node;
        tmp->field = value;
        tmp->prev = nullptr;
        tmp->next = tail;
        tail->prev = tmp;
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

    int size(){
        int i = 0;
        if (tail == nullptr){
            return 0;
        }
        else {
            Node* current = tail;
            while (current->next != nullptr){
                i++;
                current = current->next;
            }
            i++;
        }

        return i;
    }

};

int main(){
Queue Q(10);
Q.print();
Q.push(20);
Q.push(10);
Q.print();
Q.pop();
Q.print();
Q.pop();
Q.print();
std :: cout << Q.size() << std :: endl;

return 0;
}

