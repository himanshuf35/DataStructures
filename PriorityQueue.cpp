#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <typename T> class PriorityQueue {
    private: 
        vector<T> arrayRep;
        void swapElements(int first, int second);
    public:
        void enqueue(T newData);
        T dequeue();
        void print();
        int getSize();
        bool isEmpty();
};


template <typename T> void PriorityQueue<T>::swapElements(int first, int second) {
    T temp = arrayRep[first];
    arrayRep[first] = arrayRep[second];
    arrayRep[second] = temp;
}

template <typename T> void PriorityQueue<T>::enqueue(T newData) {
    arrayRep.push_back(newData);
    int currentIndex  = arrayRep.size() - 1;
    int parentIndex = ceil((float) currentIndex / 2) - 1;
    while(parentIndex >= 0) {
        if(arrayRep[currentIndex] > arrayRep[parentIndex]) {
            swapElements(currentIndex, parentIndex);
            currentIndex = parentIndex;
            parentIndex = ceil((float) currentIndex / 2) - 1;
        }
        else {
            break;
        }
    }
}

template <typename T> T PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    else {
        int currentIndex = arrayRep.size() - 1;
        swapElements(0, currentIndex);
        T removedItem = arrayRep.back();
        arrayRep.pop_back();
        int iterIndex = 0;
        while((2 * iterIndex + 1) < arrayRep.size()) {
            int leftIndex = 2 * iterIndex + 1;
            int rightIndex = 2 * iterIndex + 2;
            if(rightIndex < arrayRep.size()) {
                if(arrayRep[leftIndex] > arrayRep[iterIndex] && arrayRep[rightIndex] > arrayRep[iterIndex]) {
                    int secondIndex = arrayRep[leftIndex] > arrayRep[rightIndex] ? leftIndex : rightIndex;
                    swapElements(iterIndex, secondIndex);
                    iterIndex = secondIndex;
                }
                else if(arrayRep[leftIndex] > arrayRep[iterIndex]) {
                    swapElements(iterIndex, leftIndex);
                    iterIndex = leftIndex;
                }
                else if(arrayRep[rightIndex] > arrayRep[iterIndex]) {
                    swapElements(iterIndex, rightIndex);
                    iterIndex = rightIndex;
                }
                else {
                    break;
                }
            }
            else if(arrayRep[leftIndex] > arrayRep[iterIndex]) {
                swapElements(iterIndex, leftIndex);
                iterIndex = leftIndex;
            }
            else {
                break;
            }
        }
        return removedItem;
    }
}

template <typename T> int PriorityQueue<T>::getSize() {
    return arrayRep.size();
}

template <typename T> bool PriorityQueue<T>::isEmpty() {
    return arrayRep.size() == 0;
}

template <typename T> void PriorityQueue<T>::print() {
    for(int i = 0; i < arrayRep.size(); i++) {
        cout << arrayRep[i] << " ";
    }
    cout << "\n";
}

int main() {
    PriorityQueue<int> myQueue;
    myQueue.enqueue(4);
    myQueue.enqueue(1);
    myQueue.enqueue(8);
    myQueue.enqueue(3);
    myQueue.enqueue(2);
    myQueue.enqueue(10);
    myQueue.print();
    for(int i = 0; i < 4; i++) {
        cout << "dequeued: " << myQueue.dequeue() << "\n";
    }
    myQueue.print();
    return 0;
}
