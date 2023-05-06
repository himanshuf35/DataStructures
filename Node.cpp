#include "Node.h"
#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T> Node<T>::Node(T newData) {
    data = newData;
    next = nullptr;
    prev = nullptr;
}
 