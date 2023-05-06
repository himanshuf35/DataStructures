#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> class UnionFind {
    private:
        int charmap[26];
        void compressPath(T element, int root);
    public:
        UnionFind();
        int find(T element);
        void unionP(T first, T second);
        void unionPCompress(T first, T second);
        void print();
};

template <typename T> UnionFind<T>::UnionFind() {
    for(int i = 0; i < 26; i++) {
        charmap[i] = i;
    }
}

template <typename T> void UnionFind<T>::compressPath(T element, int root) {
    int charIndex = (int) element - 65;
    int currentIndex = charIndex;
    while(currentIndex != root){
        int temp = charmap[currentIndex];
        charmap[currentIndex] = root;
        currentIndex = temp;
    }
}

template <typename T> int UnionFind<T>::find(T element) {
    int charIndex = (int) element - 65;
    int currentIndex = charIndex;
    while(currentIndex != charmap[currentIndex]){
        currentIndex = charmap[currentIndex];
    }
    return currentIndex;
}

template <typename T> void UnionFind<T>::unionP(T first, T second) {
    int rootFirst = find(first);
    int rootSecond = find(second);
    if(rootFirst != rootSecond) {
        charmap[rootFirst] = rootSecond;
    }
}

template <typename T> void UnionFind<T>::unionPCompress(T first, T second ) {
    int rootFirst = find(first);
    int rootSecond = find(second);
    if(rootFirst != rootSecond) {
        compressPath(first, rootFirst);
        compressPath(second, rootSecond);
        charmap[rootFirst] = rootSecond;
    }
}

template <typename T> void UnionFind<T>::print() {
     for(int i = 0; i < 26; i++) {
        cout << charmap[i] << "  ";
    }
    cout << "\n";
}

int main() {
    UnionFind<char> myUnionFind;
    myUnionFind.unionP('A', 'D');
    myUnionFind.unionP('D', 'J');
    myUnionFind.unionP('D', 'K');
    myUnionFind.unionP('B', 'C');
    myUnionFind.unionP('M', 'R');
    myUnionFind.unionP('C', 'M');
    myUnionFind.unionPCompress('A', 'B');
    myUnionFind.print();
    return 0;
}
