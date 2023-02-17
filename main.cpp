#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value{};
    Node *right = nullptr, *left = nullptr;
    Node(int val);
};

Node::Node(int val) {
    this->value = val;
}

class BT {
    Node *root = nullptr;
    void inOrder(Node *rt);
    void preOrder(Node *rt);
    void postOrder(Node *rt);
public:
    BT(int val);
    void insert(int val);
    void inOrder() {
        this->inOrder(this->root);
    };
    void preOrder() {
        this->preOrder(this->root);
    };
    void postOrder() {
        this->postOrder(this->root);
    };

};

BT::BT(int val) {
    root = new Node(val);
}

void BT::insert(int val) {
    Node *newNode = new Node(val);
    Node *go = this->root;
    Node *parent = go;
    while (true) {
        parent = go;
        if (val <= parent->value) {
            go = parent->left;
            if (go == nullptr) {
                parent->left = newNode;
                return;
            }
        } else {
            go = parent->right;
            if (go == nullptr) {
                parent->right = newNode;
                return;
            }
        }
    }

}

void BT::inOrder(Node *rt) {
    Node *cur = rt;
    if (cur == nullptr) return;
    inOrder(rt->left);
    cout << cur->value << " ";
    inOrder(rt->right);
}

void BT::preOrder(Node *rt){
    Node *cur = rt;
    if(cur==nullptr) return;
    cout << cur->value << " ";
    preOrder(rt->left);
    preOrder(rt->right);
}

void BT::postOrder(Node *rt){
    Node *cur = rt;
    if(cur==nullptr) return;
    postOrder(rt->left);
    postOrder(rt->right);
    cout << cur->value << " ";
}

int main() {
    BT myTree(5);

    myTree.insert(7);myTree.insert(4);myTree.insert(9);myTree.insert(6);myTree.insert(5);myTree.insert(3);

    cout<<"PreOrder: ";
    myTree.preOrder();
    cout<<"\nInOrder: ";
    myTree.inOrder();
    cout<<"\nPostOrder: ";
    myTree.postOrder();
};
