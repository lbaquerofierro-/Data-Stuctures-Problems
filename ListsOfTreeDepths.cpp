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

    /* 4.3 List of Depths  */
    vector<list<Node<T>*>*> createLevelLinkedList(Node<T>*p);
    void createLevelLinkedList(Node<T>*p, vector<list<Node<T>*>*> &lists, int level);

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


/*    4.3 List of Depths  */

template <class T>
void BsTree<T>::createLevelLinkedList(Node<T>*p, vector<list<Node<T>*>*> &listsVector, int level){
    if(p == NULL)
        return;

    list<Node<T>*> *l = new list<Node<T>*>;

    int i = listsVector.size();
    if(listsVector.size() == level){
        listsVector.push_back(l);
    }else{
        l = listsVector[level];
    }

    l->push_back(p);
    createLevelLinkedList(p->left, listsVector, level + 1);
    createLevelLinkedList(p->right, listsVector, level + 1);
}

template <class T>
    vector<list<Node<T>*>*> BsTree<T>::createLevelLinkedList(Node<T>*p){
    vector<list<Node<T>*>*> lists;
    createLevelLinkedList(p, lists, 0);

    list<int>::iterator it;
    for(int i = 0; i < lists.size(); i++){
        for (auto &i : *(lists[i])){
            cout << i->data << " ";
        }
        cout << endl;
    }
    return lists;
}


int main(){

    int arr[] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 27};
    int numOfNodes = sizeof(arr)/ sizeof(arr[0]);

    BsTree<int> myTree;

    // Insert nodes
    for(int i = 0; i < numOfNodes; i++){
        myTree.insert(arr[i]);
    }

    // Get root of 'myTree'
    Node<int> *p = myTree.getRoot();

    myTree.createLevelLinkedList(p);

    return 0;
}
