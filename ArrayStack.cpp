#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> class Stack {
    private: 
        T* container;
        int size;
        int current;
    public: 
        Stack();
        Stack(int size);
        void push(T newData);
        T pop();
        T top();
        void print();
};

template <typename T> Stack<T>::Stack() {
    size = 1024;
    container = new T[size];
    current = -1;
}

template <typename T> Stack<T>::Stack(int newSize) {
    size = newSize;
    container = new T[newSize];
    current = -1;
}

template <typename T> void Stack<T>::push(T newData) {
    if(current == size - 1) throw runtime_error("stack is full");
    else container[++current] = newData;
}

template <typename T> T Stack<T>::pop() {
    if(current == -1) throw runtime_error("stack is empty");
    else return container[current--];
}

template <typename T> T Stack<T>::top() {
    if(current == -1) throw runtime_error("stack is empty");
    else return container[current];
}

template <typename T> void Stack<T>::print() {
    for(int iter = current; iter >= 0; iter--) {
        cout << container[iter] << " ";
    }
}