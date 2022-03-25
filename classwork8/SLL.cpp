#include<iostream>

struct Node {
    int field;
    Node* next;
};

void append(Node** head_ptr, int value){
    Node* current = *head_ptr;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node* tmp = new Node;
    tmp->next = nullptr;
    tmp->field = value;
    current->next = tmp;
}

void add(Node** head_ptr,int value, int index){

    if (index == 0){
        Node *tmp = new Node;
        tmp->field = (**head_ptr).field;
        tmp->next = (**head_ptr).next;
        (**head_ptr).field = value;
        (**head_ptr).next = tmp;
    }
    else{
        int i = -1;

        Node* current = *head_ptr;
        Node* prev = nullptr;

        while (current!= nullptr){
            i++;
            if (i == index){
                Node *tmp = new Node;
                tmp->field = value;
                prev->next = tmp;
                tmp->next = current;

                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

void print_list(Node* head_ptr){
    Node* current = head_ptr;
    if (head_ptr != nullptr){
        std :: cout << current->field << " ";

        while (current->next != nullptr){
            current = current->next;
            std :: cout << current->field << " ";
        }
        std :: cout << std :: endl;
    }
}

void pop(Node** head_ptr){


    Node* current = *head_ptr;
    if (current->next == nullptr){
        *head_ptr = nullptr;
        delete *head_ptr;
    }
    else{
        while (current->next->next!= nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

}
void delete_list(Node** head_ptr){
    Node* previous = *head_ptr;
    Node* current = (*head_ptr)->next;
    while (current->next != nullptr){
        delete previous;
        previous = current;
        current = current->next;
    }
    delete previous;
    delete current;
    *head_ptr = nullptr;


}

Node* find_by_value(Node* head_ptr, int value){


    Node* current = head_ptr;

    while(current->next != nullptr){
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
Node* find_by_index(Node* head_ptr, int index){

    Node* current = head_ptr;
    int i = 0;

    while(current->next != nullptr){
        if (i == index){
            return current ;
        }

        i++;
        current = current->next;
    }

    if (i == index){
        return current;
    }

    return nullptr;
}

Node* delete_by_value(Node** head_ptr, int value){

    Node*previous = nullptr;
    Node* current = *head_ptr;

    if (current->field == value){
        *head_ptr = (current->next);
        delete current;
        return current;
    }

    else{
        while (current->next != nullptr){
            if (current->field == value){
                previous->next = current->next;
                delete current;
                return current;
                break;
            }
            previous = current;
            current = current->next;
        }
        if (current->field == value){
            previous->next = nullptr;
            delete current;
            return current;
        }
    }
    return nullptr;
}

Node* delete_by_index(Node** head_ptr, int index){

    Node*previous = nullptr;
    Node* current = *head_ptr;
    int i = 0;

    if (index == 0){
        *head_ptr = (current->next);
        delete current;
        return current;
    }
    else{
        while (current->next != nullptr){
            if (i == index){
                previous->next = current->next;
                delete current;
                return current;
            }
            previous = current;
            current = current->next;
            i++;
        }
        if (current->field == index){
            previous->next = nullptr;
            delete current;
            return current;
        }
    }
    return nullptr;
}

struct List {
    Node* head = new Node;


    List (int value){
        head->field = value;
        head->next = nullptr;
      }

    void append_List(int value){
        append(&head, value);
    }

    void add_List(int value, int index){
        add(&head, value, index);
    }

    void pop_List(){
        pop(&head);
    }

    void print_List(){
        print_list(head);
    }

    void delete_List(){
        delete_list(&head);
    }

    Node* find_by_value_List(int value){
        return find_by_value(head, value);
    }

    Node* find_by_index_List(int index){
        return find_by_index(head, index);
    }

    Node* delete_by_value_List(int value){
        return delete_by_value(&head, value);
    }

    Node* delete_by_index_List(int index){
        return (delete_by_index(&head, index));
    }

};

int main(){
List A(0);

for (int i = 1; i < 10;i++){
    A.append_List(i);
}
A.print_List();
std :: cout << A.delete_by_value_List(5) << std :: endl;
A.print_List();
std :: cout << A.find_by_value_List(1);

return 0;
}

