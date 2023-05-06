#include<stdio.h>
#include<iostream>

using namespace std;

template <typename T> struct TreeNode {
    T data;
    T* left;
    T* right;
    TreeNode(T newData);
};

template <typename T> TreeNode<T>::TreeNode(T newData) {
    data = newData;
    left = nullptr;
    right = nullptr;
}