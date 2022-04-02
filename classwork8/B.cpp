#include <iostream>

struct Node{
    int value;
    Node* next;
};

struct List{
    Node* head;

    List (int value){

    head = new Node;
    head->next = nullptr;
    head->value;
    }

    void append(int value){

        Node* tmp = new Node;
        tmp->next = nullptr;
        tmp->value = value;

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



int find_loop(List* list_ptr) {

	if ((list_ptr->head == nullptr) || (list_ptr == nullptr)) {
		return -1;
	}

	else {
		bool looped = false;

        Node* hair = list_ptr->head;
        Node* turtle = list_ptr->head;

		while (true) {

            if (hair->next == nullptr){
                looped = false;
                break;
            }
             if (hair->next->next == nullptr){
                looped = false;
                break;
            }

            turtle = turtle->next;
            hair = hair->next->next;

            if (turtle == hair){
                looped = true;
                break;
            }
		}

		if (looped) {
            int result = 0;
            turtle = list_ptr->head;
            while (turtle != hair){
                turtle = turtle->next;
                hair = hair->next;
                result++;
            }
            return result;
		}

		else {
			return -1;
		}
	}
}

int main(){

List A(0);
for (int i = 1; i < 10; i++)
{
    A.append(10);
}
std :: cout << find_loop(&A) << '\n';
A.head->next->next = A.head->next;
std :: cout << find_loop(&A);



return 0;
}

