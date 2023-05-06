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
 

template <typename T> class DoublyLinkedList {
    private:
        int currentSize;
        Node<T>* head;
        Node<T>* tail;
    public: 
        DoublyLinkedList();
        void push(T newData);
        void unshift(T newData);
        void pop();
        void shift();
        void insertAt(int position, T newData);
        void removeAt(int position);
        void print();
};

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {
    currentSize = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T> void DoublyLinkedList<T>::push(T newData) {
    Node<T>* newNode = new Node<T>(newData);
    if(head == nullptr) {
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    currentSize++;
}

template <typename T> void DoublyLinkedList<T>::unshift(T newData) {
    Node<T>* newNode = new Node<T>(newData);
    if(head == nullptr) {
        head = newNode;
        tail = head;
    }
    else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;  
    }
    currentSize++;
}

template <typename T> void DoublyLinkedList<T>::pop() {
    if(tail == nullptr) {
        //TODO
    }
    else {
        Node<T>* nodeToBeDeleted = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        delete nodeToBeDeleted;
    }
     currentSize--;
}

template <typename T> void DoublyLinkedList<T>::shift() {
    if(head == nullptr) {
        //TODO
    }
    else {
        Node<T>* nodeToBeDeleted = head;
        head = head -> next;
        head -> prev = nullptr;
        delete nodeToBeDeleted;
    }
    currentSize--;
}

template <typename T> void DoublyLinkedList<T>::insertAt(int position, T newData) {
    if(position == 1) {
        unshift(newData);
    }
    else {
        int counter = 1;
        Node<T>* currentPtr = head;
        Node<T>* newNode = new Node<T>(newData);
        while(counter < position - 1) {
            currentPtr = currentPtr -> next;
            counter++;
        }
        Node<T>* tempNode = currentPtr -> next;
        currentPtr -> next = newNode;
        newNode -> prev = currentPtr;
        newNode -> next = tempNode;
        tempNode -> prev = newNode;
        currentSize++;
    }
}

template <typename T> void DoublyLinkedList<T>::removeAt(int position) {
    if(position == 1) {
        shift();
    }
    else if(position == currentSize) {
        pop();
    }
    else {
        int counter = 1;
        Node<T>* currentPtr = head;
        while(counter < position - 1) {
            currentPtr = currentPtr -> next;
            counter++;
        }
        Node<T>* nodeToBeDeleted = currentPtr -> next;
        Node<T>* nextNode = currentPtr -> next -> next;
        nextNode -> prev = currentPtr;
        currentPtr -> next = nextNode;
        delete nodeToBeDeleted;
        currentSize--;
    }
}

template <typename T> void DoublyLinkedList<T>::print() {
    Node<T>* currentPtr = head;
    while(currentPtr != nullptr) {
        cout << currentPtr -> data << " ";
        currentPtr = currentPtr -> next;
    } 
}

int main() {
    DoublyLinkedList<int> list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    list.insertAt(6, 7);
    list.removeAt(6);
    list.removeAt(1);
    list.print();
    return 0;
}