#include <iostream>
#include <queue>
#include <list>
#include <map>

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

    void insert(T val);
    Node<T>* insert(T val, Node<T>* p);

    /*  Check if a binary tree is BST   */
    bool checkIfBST(Node<T> *p);
    bool isSubtreeGreater(Node<T> *p, T val);
    bool isSubtreeLesser(Node<T> *p, T val);

    bool isBSTmethod2(Node<T> *p, int minValue, int maxValue);

    Node<T>* getRoot(){return root; };
};

template <class T>
void BsTree<T>::insert(T val){
    root = insert(val, root);
}


template <class T>
Node<T>* BsTree<T>::insert(T val, Node<T> *p){

    if(p == NULL){
        Node<T> *newNode = new Node<T>(val);
        p = newNode;
    }else if(val <= p->data){
        p->left = insert(val, p->left);
    }else if(val > p->data){
        p->right = insert(val, p->right);
    }

    return p;
}

//Check if a tree is a BST
template <class T>
bool BsTree<T>::isSubtreeLesser(Node<T> *p, T val){
    if(p == NULL) return true;
    if(p->data <= val
       && isSubtreeLesser(p->left, val)
       && isSubtreeLesser(p->right, val)){

        return true;
    } else
        return false;
}

template <class T>
bool BsTree<T>::isSubtreeGreater(Node<T> *p, T val){
    if(p == NULL) return true;
    if(p->data <= val
       && isSubtreeGreater(p->left, val)
       && isSubtreeGreater(p->right, val)){

        return true;
    } else
        return false;
}

template <class T>
bool BsTree<T>::checkIfBST(Node<T> *p){
    if(p == NULL) return true;
    if(isSubtreeLesser(p->left, p->data)
       && isSubtreeGreater(p->right, root->data)
       && checkIfBST(p->left)                  //We also need to know if left
       && checkIfBST(p->right)){               //and right subtrees are BST

        return true;
    }else
        return false;

}

template <class T>
bool BsTree<T>::isBSTmethod2(Node<T> *p, int minValue, int maxValue){
    if(p == NULL) return  true;
    if(p->data > minValue
       && p->data < maxValue
       && isBSTmethod2(p->left, minValue, p->data)
       && isBSTmethod2(p->right, p->data, maxValue))
        return true;
    else
        return false;

}

int main(){
    int arr[] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 27};

    int numOfNodes = sizeof(arr)/ sizeof(arr[0]);

    BsTree<int> myTree;

    for(int i = 0; i < numOfNodes; i++){
        myTree.insert(arr[i]);
    }

    myTree.checkIfBST(p);

    return 0;
}
