#include<stdio.h>
#include<iostream>

using namespace std;

template <typename T> struct TreeNode {
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;
    bool isLeft;
    TreeNode(T newData);
};

template <typename T> TreeNode<T>::TreeNode(T newData) {
    value = newData;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    isLeft = false;
}

template <typename T> class BST {
    private:
        TreeNode<T>* root;
        int size;
        void insertWithNode(TreeNode<T>* node, TreeNode<T>* newNode);
        void addRight(TreeNode<T>* node, TreeNode<T>* newNode);
        void addLeft(TreeNode<T>* node, TreeNode<T>* newNode);
        void preOrder(TreeNode<T>* node);
        void inOrder(TreeNode<T>* node);
        void postOrder(TreeNode<T>* node);
        void deleteNode(TreeNode<T>* node, TreeNode<T>* replacementNode);
        TreeNode<T>* searchWithNode(TreeNode<T>* node, T searchValue);
        TreeNode<T>* getLargestNode(TreeNode<T>* node);
        TreeNode<T>* getSmallestNode(TreeNode<T>* node);
    public: 
        BST();
        void insert(T newData);
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void remove(T value);
        TreeNode<T>* getLargest();
        TreeNode<T>* getSmallest();
        TreeNode<T>* search(T searchValue);
};

template <typename T> BST<T>::BST() {
    root = nullptr;
    size = 0;
}

//private methods
template <typename T> void BST<T>::insertWithNode(TreeNode<T> * node, TreeNode<T> * newNode) {
   if(newNode -> value > node -> value) {
        if(node -> right != nullptr) {
            insertWithNode(node -> right, newNode);
        }
        else {
            addRight(node, newNode);
        }
    }
    else {
        if(node -> left != nullptr) {
            insertWithNode(node -> left, newNode);
        }
        else {
            addLeft(node, newNode);
        }
    }
    size++;
}

template <typename T> void BST<T>::addRight(TreeNode<T>* node, TreeNode<T>* newNode) {
    node -> right = newNode;
    newNode -> parent = node;
    newNode -> isLeft = false;
}

template <typename T> void BST<T>::addLeft(TreeNode<T>* node, TreeNode<T>* newNode) {
    node -> left = newNode;
    newNode -> parent = node;
    newNode -> isLeft = true;
}

template <typename T> TreeNode<T>* BST<T>::searchWithNode(TreeNode<T>* node, T searchValue) {
    if(node == nullptr) {
        return nullptr;
    }
    else if(node -> value == searchValue) {
        return node;
    }
    else if(searchValue > node -> value) {
        return searchWithNode(node -> right, searchValue);
    }
    else {
        return searchWithNode(node -> left, searchValue);
    }
}

template <typename T> void BST<T>::preOrder(TreeNode<T>* node) {
    if(node != nullptr) {
        cout << node -> value << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

template <typename T> void BST<T>::inOrder(TreeNode<T>* node) {
    if(node != nullptr) {
        inOrder(node -> left);
        cout << node -> value << " ";
        inOrder(node -> right);
    }
}

template <typename T> void BST<T>::postOrder(TreeNode<T>* node) {
    if(node != nullptr) {
        postOrder(node -> left);
        postOrder(node -> right);
        cout << node -> value << " ";
    }
}

template <typename T> TreeNode<T>* BST<T>::getLargestNode(TreeNode<T>* node) {
    if(node -> right == nullptr) {
        return node;
    }
    else return getLargestNode(node -> right);
}

template <typename T> TreeNode<T>* BST<T>::getSmallestNode(TreeNode<T>* node) {
    if(node -> left == nullptr) {
        return node;
    }
    else return getSmallestNode(node -> left);
}

template <typename T> void BST<T>::deleteNode(TreeNode<T>* node, TreeNode<T>* replacementNode) {
    TreeNode<T>* parentNode = node -> parent;
    if(parentNode == nullptr) {
        root = nullptr;
    }
    else {
        if(node -> isLeft) parentNode -> left = replacementNode;
        else parentNode -> right = replacementNode;
        if(replacementNode != nullptr) {
            replacementNode -> isLeft = node -> isLeft;
            replacementNode -> parent = parentNode;
        }
    }
    delete node;
}



//public methods
template <typename T> void BST<T>::insert(T newData) {
    TreeNode<T>* newNode = new TreeNode<T>(newData);
    if(root == nullptr) {
        root = newNode;
    }
    else {
        insertWithNode(root, newNode);
    }
}

template <typename T> TreeNode<T>* BST<T>::search(T searchValue) {
    return searchWithNode(root, searchValue);
}

template <typename T> void BST<T>::printPreOrder() {
    preOrder(root);
    cout << "\n";
}

template <typename T> void BST<T>::printInOrder() {
    inOrder(root);
    cout << "\n";
}

template <typename T> void BST<T>::printPostOrder() {
    postOrder(root);
    cout << "\n";
}

template <typename T> void BST<T>::remove(T value) {
    TreeNode<T>* searchedNode = searchWithNode(root, value);
    if(searchedNode != nullptr) {
        if(searchedNode -> left == nullptr && searchedNode -> right == nullptr) {
            deleteNode(searchedNode, nullptr);
        }
        else if(searchedNode -> right == nullptr) {
            deleteNode(searchedNode, searchedNode -> left);
        }
        else if(searchedNode -> left == nullptr) {
            deleteNode(searchedNode, searchedNode -> right);
        }
        else {
            TreeNode<T>* smallestNode = getSmallestNode(searchedNode -> right);
            searchedNode -> value = smallestNode -> value;
            deleteNode(smallestNode, nullptr);
        }
    }
    else throw runtime_error("Given value does not exist in tree");
}

template <typename T> TreeNode<T>* BST<T>::getLargest() {
    return getLargestNode(root);
}

template <typename T> TreeNode<T>* BST<T>::getSmallest() {
    return getSmallestNode(root);
}

int main() {
    BST<int> myTree;
    myTree.insert(10);
    myTree.insert(15);
    myTree.insert(14);
    myTree.insert(7);
    myTree.insert(9);
    myTree.insert(1);
    myTree.insert(12);
    myTree.insert(18);
    myTree.insert(6); 
    myTree.insert(3); 
    myTree.insert(5); 
    myTree.insert(11);
    myTree.insert(19);
    myTree.insert(16);
    myTree.remove(5);
    myTree.remove(1);
    myTree.remove(15);
    myTree.printPreOrder();
    myTree.printInOrder();
    myTree.printPostOrder();
    return 0;
}

