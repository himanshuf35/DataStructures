#include <stdio.h>
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T> class SinglyLinkedList {
    private: 
        int currentSize;
        Node<T>* head;
        Node<T>* tail;
    public: 
        SinglyLinkedList();
        void push(T newData);
        void unshift(T newData);
        void pop();
        void print();
        void shift();
        void insertAt(int position, T newData);
        void removeAt(int position);
        void reverse();
};

template <typename T> SinglyLinkedList<T>::SinglyLinkedList() {
    currentSize = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T> void SinglyLinkedList<T>::push(T newData) {
    Node<T>* newNode = new Node<T>(newData);
    if(head == nullptr) {
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
    currentSize++;
}

template <typename T> void SinglyLinkedList<T>::unshift(T newData) {
    Node<T>* newNode = new Node<T>(newData);
    if(head == nullptr) {
        head = newNode;
        tail = head;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
    currentSize++;
}

template <typename T> void SinglyLinkedList<T>::pop() {
    int i = 1;
    Node<T>* currentPtr = head;
    while(i < currentSize - 1) {
       currentPtr = currentPtr -> next;
       i++;
    }
    Node<T>* deletedNode = currentPtr -> next;
    currentPtr -> next = nullptr;
    tail = currentPtr;
    currentSize--;
    delete deletedNode;
}

template <typename T> void SinglyLinkedList<T>::print() {
    Node<T>* currentPtr = head;
    while(currentPtr != nullptr) {
        cout << currentPtr -> data << "  ";
        currentPtr = currentPtr -> next;
    }
    cout << "\n";
}

template <typename T> void SinglyLinkedList<T>::shift() {
   if(head != nullptr) {
        Node<T>* deletedNode = head;
        head = head -> next;
        delete deletedNode;
        currentSize--;
   }
}

template <typename T> void SinglyLinkedList<T>::insertAt(int position, T newData) {
    if(position == 1) {
        unshift(newData);
    }
    else {
         int currentPosition = 1;
        Node<T>* currentPtr = head;
        while(currentPosition < position - 1) {
            currentPtr = currentPtr -> next;
            currentPosition++;
        }
        Node<T>* newNode = new Node<T>(newData);
        Node<T>* tempNode = currentPtr -> next;
        currentPtr -> next = newNode;
        newNode -> next = tempNode;
        currentSize++;
    }
}

template <typename T> void SinglyLinkedList<T>::removeAt(int position) {
    if(position == 1) {
        shift();
    }
    else if (position == currentSize) {
        pop();
    }
    else {
        int currentPosition = 1;
        Node<T>* currentPtr = head;
        while(currentPosition < position - 1) {
            currentPtr = currentPtr -> next;
            currentPosition++;
        }
        Node<T>* nodeToBeDeleted = currentPtr -> next;
        currentPtr -> next = currentPtr -> next -> next;
        nodeToBeDeleted -> next = nullptr;
        delete nodeToBeDeleted;
        currentSize--;
    }
}

template <typename T> void SinglyLinkedList<T>::reverse() {
   Node<T>* current = head;
   while(current -> next != nullptr) {
        Node<T>* temp = head;
        Node<T>* next = current -> next;
        current -> next = next -> next;
        head = next;
        head -> next = temp;
   }
   tail = current;
}

int main() {
    SinglyLinkedList<int> list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    list.print();
    list.reverse();
    list.print();
    list.unshift(7);
    list.print();
    return 0;
}