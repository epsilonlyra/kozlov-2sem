#include <iostream>
using namespace std;

struct Node{

    char name [20];
    Node* next;
    Node* prev;
};

struct People{

    Node* head;

    People(int N){
        head = new Node;
        head->next = head;
        head->prev = head;
        std ::cin >> head->name;
        Node* current = head;
        for (int i = 0; i < N - 1; i++){
            Node* tmp = new Node;
            tmp->next = head;
            tmp->prev = current;

            current->next = tmp;
            head->prev = tmp;

            std :: cin >> tmp->name;
            current = current->next;
        }
    }

    void kill(int m){
        int i = 1;
        Node* current = head;
        while (i != m){
            current = current->next;
            i += 1;
        }

        head = current->next;
        (current->prev)->next = current->next;
        (current->next)->prev = current->prev;
        }


    Node* elect(int m){
        while ( (head->next) != head ){
            kill(m);
        }
        return (head);
    }
};



int main(){
int N, m;
std :: cin >> N;
People Group(N);
std :: cin >> m;

Node* president  = Group.elect(m);
std :: cout << (president->name);
std :: cout << '\n';

return 0;
}
