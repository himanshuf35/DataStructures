#include <iostream>
using namespace std;

template <typename T> class DynamicArray {
    private:
        T * ContArray;
        int currentSize;
        int currentIndex;
    public:
        DynamicArray();
        DynamicArray(int size);
        void add(T newElement);
        void remove(T existingElement);
        void print();
};

template <typename T> DynamicArray<T>::DynamicArray() {
    ContArray = new T[2];
    currentSize = 2;
    currentIndex = 0;
}

template <typename T> DynamicArray<T>::DynamicArray(int size) {
    ContArray = new T[size];
    currentSize = size;
    currentIndex = 0;
}

template <typename T> void DynamicArray<T>::add(T newElement) {
    if(currentIndex > currentSize - 1) {
        //if existing array is already full then 
        //create a new array with double the size and copy/paste previous element array into new one
        T * tempArray = new T[currentSize * 2];
        for(int i = 0; i < currentSize; i++) {
            tempArray[i] = ContArray[i];
        }
        ContArray = tempArray;
        currentSize *= 2;
    }
    ContArray[currentIndex] = newElement;
    currentIndex += 1;
}

template <typename T> void DynamicArray<T>::remove(T existingElement) {
    int elementIndex = -1;
    for(int i = 0; i < currentIndex; i++) {
        if(ContArray[i] == existingElement) {
            elementIndex = i;
            break;
        }
    }
    if(elementIndex != -1) {
        for(int j = elementIndex; j < currentIndex - 1; j++) {
            ContArray[j] = ContArray[j + 1];
        }
        ContArray[currentIndex - 1] = NULL;
        currentIndex -= 1;
    }
}

template <typename T> void DynamicArray<T>::print() {
    cout << "currentSize: " << currentSize << "\n";
    cout << "currentIndex: " << currentIndex << "\n";
    for(int i = 0; i < currentIndex; i++) {
        cout << ContArray[i] << "  ";
    }
}