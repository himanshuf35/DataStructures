#include <iostream>
#include <stdio.h>

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

template <typename T> class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        Queue();
        void enqueue(T newData);
        T dequeue();
        int getSize();
        bool isEmpty();
        void print(); 
        T front();
        T end();
};

template <typename T> Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T> void Queue<T>::enqueue(T newData) {
    Node<T>* newNode = new Node<T>(newData);
    if(isEmpty()) {
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T> T Queue<T>::dequeue() {
    if(isEmpty()) {
       throw runtime_error("Queue is already empty");
    }
    else {
        Node<T>* nodeToBeDeleted = head;
        T returnData = nodeToBeDeleted -> data;
        head = head -> next;
        delete nodeToBeDeleted;
        size--;
        return returnData;
    }
}

template <typename T> T Queue<T>::front() {
    if(isEmpty()) {
        throw runtime_error("Queue is already empty");
    }
    else {
        return head -> data;
    }
}

template <typename T> T Queue<T>::end() {
    if(isEmpty()) {
        throw runtime_error("Queue is already empty");
    }
    else {
        return tail -> data;
    }
}

template <typename T> int Queue<T>::getSize() {
    return size;
}

template <typename T> bool Queue<T>::isEmpty() {
    return size == 0;
}

template <typename T> void Queue<T>::print() {
    Node<T>* current = head;
    while(current != nullptr) {
        cout << current -> data << " ";
        current = current -> next;
    }
}

int main() {
    Queue<int> myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.dequeue();
    int frontElement = myQueue.front();
    cout << "front: " << frontElement << "\n";
    int endElement = myQueue.end();
    cout << "end: " << endElement << "\n";
    int size = myQueue.getSize();
    cout << "size: " << size << "\n";
    myQueue.dequeue();
    myQueue.enqueue(4);
    myQueue.print();
    return 0;
}