#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> class Queue {
    private:
        T* container;
        int size;
        int front;
        int back;
        int itemCount;
    public:
        Queue();
        Queue(int newSize);
        void enqueue(T newData);
        T dequeue();
        bool isEmpty();
        T frontItem();
        T backItem();
        void print();
};

template <typename T> Queue<T>::Queue() {
    size = 10;
    container = new T[size];
    front = 0;
    back = 0;
    itemCount = 0;
}

template <typename T> Queue<T>::Queue(int newSize) {
    size = newSize;
    container = new T[newSize];
    front = 0;
    back = 0;
    itemCount = 0;
}

template <typename T> void Queue<T>::enqueue(T newData) {
    if(itemCount == size) {
        throw runtime_error("queue is full");
    }
    else if (back == size) back = 0;
    container[back++] = newData;
    itemCount++;
}

template <typename T> T Queue<T>::dequeue() {
    if(isEmpty()) throw runtime_error("queue is empty") ;
    else if(front == size) front = 0;
    int position = front;
    int returnValue = container[front++];
    itemCount--;
    container[position] = -1;
    return returnValue;
}

template <typename T> bool Queue<T>::isEmpty() {
    return itemCount == 0;
}

template <typename T> T Queue<T>::frontItem() {
    return container[front];
}

template <typename T> T Queue<T>::backItem() {
     return container[back - 1];
}

template <typename T> void Queue<T>::print() {
    for(int i = 0; i < size; i++) {
        cout << container[i] << " ";
    }
}

int main() {
    Queue<int> myQueue;
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    cout << myQueue.frontItem() << "\n";
    cout << myQueue.backItem() << "\n"; 
    myQueue.print();
    return 0;
}
