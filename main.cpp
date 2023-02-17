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

    bool find(int val, Node *rt);

    void BFS(Node *rt);
    int height(Node *rt);

public:
    BT(int val);

    void insert(int val);

    void preOrder() {
        this->preOrder(this->root);
    };

    void inOrder() {
        this->inOrder(this->root);
    };

    void postOrder() {
        this->postOrder(this->root);
    };

    bool find(int val) {
        return this->find(val, this->root);
    };

    int height() {
        return height(this->root);
    }

    void BFS(){
        BFS(this->root);
    }

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

void BT::preOrder(Node *rt) {
    Node *cur = rt;
    if (cur == nullptr) return;
    cout << cur->value << " ";
    preOrder(rt->left);
    preOrder(rt->right);
}

void BT::postOrder(Node *rt) {
    Node *cur = rt;
    if (cur == nullptr) return;
    postOrder(rt->left);
    postOrder(rt->right);
    cout << cur->value << " ";
}

bool BT::find(int val, Node *rt) {
    Node *cur = rt;
    if (cur == nullptr)
        return false;
    if (cur->value == val) {
        return true;
    }
    if (val < cur->value)
        find(val, cur->left);
    else {
        find(val, cur->right);
    }
}

int BT::height(Node *rt) {
    auto cur = rt;
    if (cur == nullptr) return 0;
    int lHegiht = height(cur->left);
    int rHegiht = height(cur->right);
    if (lHegiht > rHegiht)
        return lHegiht + 1;
    else
        return rHegiht + 1;

}


void BT::BFS(Node *rt){
        queue <Node *> qu;
        qu.push(rt);
        while(!qu.empty())
        {
            if (qu.front() != NULL){
                cout << qu.front()->value << " ";
                qu.push(qu.front()->left);
                qu.push(qu.front()->right);
            }
            qu.pop();
        }
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    BT myTree(5);

    myTree.insert(7);
    myTree.insert(4);
    myTree.insert(9);
    myTree.insert(6);
    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(10);
    myTree.insert(12);

    cout << "PreOrder: ";
    myTree.preOrder();
    cout << "\nInOrder: ";
    myTree.inOrder();
    cout << "\nPostOrder: ";
    myTree.postOrder();
    cout << endl << "Does Value 6 Exist? " << boolalpha << myTree.find(6);
    cout << endl << "Height: "<< myTree.height();
    cout << endl << "BFS: "; myTree.BFS();
};
