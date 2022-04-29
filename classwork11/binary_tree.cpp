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
    element->parent = nullptr;

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

    element->parent = pre;
}

void pre_order(Node* n){
    if (n == nullptr){
        return;
    }
    std :: cout << n->value << '\n';
    pre_order(n->left);
    pre_order(n->right);
}

void in_order(Node* n){
    if (n == nullptr){
        return;
    }
    in_order(n->left);
    std :: cout << n->value << '\n';
    in_order(n->right);
}

void post_order(Node* n){
    if (n == nullptr){
        return;
    }
    post_order(n->left);
    post_order(n->right);
    std :: cout << n->value << '\n';
}

Node* find(Node* n, int value){
    if (n == nullptr){
        return nullptr;
    }

    if (n->value == value){
        return n;
    }

    if (n->value < value){
        return(find(n->right, value));
    }
    else{
        return(find(n->left, value));
    }
}

Node* min(Node* root){
    if (root == nullptr){
        return nullptr;
    }

    Node* element = root;
    while (element->left != nullptr){
        element = element->left;
    }

    return(element);
}

Node* max(Node* root){
    if (root == nullptr){
        return nullptr;
    }

    Node* element = root;

    while (element->right != nullptr){
        element = element->right;
    }

    return(element);
}

void remove(Node** root, int value){

    Node* element = find(*root, value);
    if (element == nullptr){
        return;
    }

    if (element->left == nullptr && element->right == nullptr){

        if (element == *root){
            delete *root;
            *root = nullptr;
            return;
        }

        if (element->parent->left == element){
            element->parent->left = nullptr;
        }
        else{
            element->parent->right = nullptr;
        }

        delete element;

        return;
    }

    Node* changer;

    if (element->right != nullptr){
        changer = min(element->right);
        changer->parent->left = nullptr;
    }
    else{
        changer = max(element->left);
        changer->parent->right == nullptr;
    }

    changer->parent = element->parent;

    if (element == *root){

        changer->left = element->left;
        changer->right = element->right;
        *root = changer;

        delete element;
        return;
    }

    if (element->parent->left == element){
        element->parent->left = changer;
    }
    else{
        element->parent->right = changer;
    }

    delete element;
}

int main(){

Node* root = nullptr;
for (int i = 0; i < 5; i ++){
    int temp;
    std :: cin >> temp;
    add(&root, temp);
}

remove(&root, 5);

std :: cout << root->right->value;

return 0;
}
