#include <iostream>
#include <queue>
#include <vector>

using namespace std;


template <class T>
class Node{
public:
    T data;
    Node* left;
    Node* right;

    Node(T val){
        data = val;
        left = right = NULL;
    }
};

template <class T>
class BsTree{
private:
    Node<T>* root;
public:
    BsTree(){
        root = NULL;
    }

    /* 4.2 Minimal Tree */
    Node<T>* createMinimalBST(vector<int> v);
    Node<T>* createMinimalBST(vector<int> v, int start, int end);

};

template <class T>
Node<T>* BsTree<T>::createMinimalBST(vector<int> v){
    return createMinimalBST(v, 0, v.size() - 1);
}

template <class T>
Node<T>* BsTree<T>::createMinimalBST(vector<int> v, int start, int end){
    if(start > end){
        return  NULL;
    }
    int mid = (start + end) / 2;
    Node<T>* p = new Node<T>(v[mid]);
    p->left = createMinimalBST(v, start, mid - 1);
    p->right = createMinimalBST(v, mid + 1, end);
    return p;
}

int main(){
    BsTree<int> tree;
    vector<int> v = {6, 8, 10, 11, 12, 15, 16, 17, 20, 25, 27};

    Node<int>* TreeRoot = tree.createMinimalBST(v);

    return 0;
}