#include<iostream>

struct Node{
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    int value = 0;

};

void add(Node** root, int value){

    Node* pre = nullptr;
    Node* current = *root;

    Node* element = new Node;

    element->value = value;
    element->parent = pre;

    if (*root == nullptr){
        *root = element;
        return;
    }

    while(current != nullptr){
        pre = current;
        if (pre->value > value){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }

    if (pre-> value > value){
        pre->left = element;
    }
    else{
        pre->right = element;
    }
}

int main(){

Node* root = nullptr;

add(&root, 1);
add(&root, -1);
std :: cout << root->left->value;


return 0;
}
