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

    List(){
        head = nullptr;
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

        if (head == nullptr){ // если список пустой создайте
            append_list(value);
        }
        else{
            while(current != tail){
                if (i == index){
                    Node* tmp = new Node;
                    tmp->field = value;
                    tmp->next = current;
                    tmp->prev = current->prev;

                    if (current->prev != nullptr){ //если мы вставляем не в начало
                        (current->prev)->next = tmp;
                    }
                    else{
                        head = tmp;
                    }
                    current->prev = tmp;
                }
                i ++;
                current = current->next;
            }
            if (i == index){ // если оказалось что мы вставляем в конец
                Node* tmp = new Node;
                tmp->field = value;
                tmp->next = tail;
                tmp->prev = tail->prev;
                if (tail->prev != nullptr){ // если до хвоста что то есть
                    (tail->prev)->next = tmp;
                }
                else{
                    head = tmp;
                }
            }
        }
    }

    void pop(){
        if (tail != nullptr){
            if (tail->prev == nullptr){
                delete  tail;
                tail = nullptr;
                head = nullptr;
            }
            else{
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
        }
    }

    void delete_list(){
        while (head != nullptr){
            pop();
        }
    }

    Node* find_by_value(int value){
        Node* current = head;

        if (current == nullptr){
            return nullptr;
        }

        while (current->next != nullptr){
            if (current->field == value){
                return current;
            }
            current = current->next;
        }

        if (current->field == value){
            return current;
        }

        return nullptr;
    }

    Node* find_by_index(int index){
        Node* current = head;
        int i = 0;

        if (current == nullptr){
            return nullptr;
        }

        while (current->next != nullptr){
            if (i == index){
                return current;
            }
            current = current->next;
            i++;
        }

        if (i == index){
            return current;
        }
        return nullptr;
    }

    int size(){
        int i = 0;
        Node* current = head;

        if (current == nullptr){
            return 0;
        }

        while (current->next != nullptr){
            i++;
            current = current->next;
        }
        i++;

        return i;
    }

    Node* delete_by_value(int value){

        Node* current = head;

        if (current == nullptr){
            return current;
        }

        while (current->next != nullptr){

            if (current->field == value){

                if (current->prev != nullptr){
                    (current->prev)->next = current->next;
                    (current->next)->prev = current->prev;
                }

                else {
                    head = current->next;
                }

                delete current;
                return current;
            }

            current = current->next;
        }
        if (current->field == value){
            pop();
            return current;

        }
        return nullptr;
    }

    Node* delete_by_index(int index){

        Node* current = head;
        int i = 0;

        if (current == nullptr){
            return current;
        }

        while (current->next != nullptr){

            if (i == index){

                if (current->prev != nullptr){
                    (current->prev)->next = current->next;
                    (current->next)->prev = current->prev;
                }

                else {
                    head = current->next;
                }

                delete current;
                return current;
            }

            current = current->next;
            i++;
        }
        if (i== index){
            pop();
            return current;

        }
        return nullptr;
    }




};

int main(){

List A;
A.print_list();
for (int i = 1; i < 10; i++){
    A.append_list(i * i);
}
A.print_list();
std :: cout << A.delete_by_index(8) << std :: endl;
A.print_list();
return 0;
}


