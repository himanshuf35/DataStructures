#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> struct Node
{
    T data;
    Node* next;
    Node* prev;
    Node(T data);
};

template <typename T> Node<T>::Node(T newData) {
    data = newData;
    next = nullptr;
    prev = nullptr;
}

template <typename T> class Stack {
    private:
        Node<T>* tail;
        int size;
    public:
        Stack();
        void push(T newData);
        T pop();
        int getSize();
        bool isEmpty();
        T top(); 
        void print();
};

template <typename T> Stack<T>::Stack() {
    tail = nullptr;
    size = 0;
}

template <typename T> int Stack<T>::getSize() {
    return size;
}

template <typename T> void Stack<T>::push(T newData) {
    Node<T>* newNode = new Node<T>(newData);
    if(isEmpty()) {
        tail = newNode;
    }
    else {
        newNode -> prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T> T Stack<T>::pop() {
    if(isEmpty()) {
        throw runtime_error("stack is already empty");
    }
    else {
        Node<T>* nodeToBeDeleted = tail;
        T returnData = nodeToBeDeleted -> data;
        tail = tail -> prev;
        size--;
        delete nodeToBeDeleted;
        return returnData;
    }
}

template <typename T> T Stack<T>::top() {
   if(isEmpty()) {
        throw runtime_error("stack is already empty");
    }
    else {
        return tail -> data;
    }
}

template <typename T> bool Stack<T>::isEmpty() {
    return size == 0;
}

template <typename T> void Stack<T>::print() {
    Node<T>* current = tail;
    while(current != nullptr) {
        cout << current -> data << " ";
        current = current -> prev;
    }
}

int main() {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.pop();
    int topElement = myStack.top();
    cout << "top: " << topElement << "\n";
    int size = myStack.getSize();
    cout << "size: " << size << "\n";
    myStack.push(5);
    myStack.print();
    return 0;
}