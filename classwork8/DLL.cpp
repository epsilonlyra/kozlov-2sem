#include<iostream>


struct Node{

    int field;

    Node* prev;
    Node* next;
};

struct List{

	Node* head;
	Node* tail;


	List (int value) {
		head = new Node;
		head->next = nullptr;
		head->prev = nullptr;
		head->field = value;
		tail = head;
	}

	void print_list (){
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

	void append_list(int value){

        if (tail != nullptr){
            Node* tmp = new Node;
            tmp->field = value;
            tmp->next = nullptr;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        else{
            tail = new Node;
            tail->next = nullptr;
            tail->prev = nullptr;
            tail->field = value;
            head = tail;
        }

	}

    void add(int value, int index){
        int i = 0;
        Node* current = head;

        if (head == nullptr){
            append_list(value);
        }
        else{
            while(current != tail){
                if (i == index){
                    Node* tmp = new Node;
                    tmp->field = value;
                    tmp->next = current;
                    tmp->prev = current->prev;

                    (current->prev)->next = tmp;
                    current->prev = tmp;
                }
                i += 1;
                current = current->next;
            }
            if (i == index){
                Node* tmp = new Node;
                tmp->field = value;
                tmp->next = tail;
                tmp->prev = tail->prev;
                (tail->prev)->next = tmp;
            }
        }
    }
};

int main(){

List A(0);
A.print_list();
for (int i = 1; i < 10; i++){
    A.append_list(i);
}
A.print_list();

return 0;
}


