#include <stdio.h>
#include <iostream>

using namespace std;

void recurse(int source[], int level) {
    if(level == 0) {
        cout << "\n";
    }
    else {
        for(int i = 0; i < 3; i++) {
            cout << source[i] << " -> ";
            int newLevel = level - 1;
            recurse(source, newLevel);
        }
    }
}


int main() {
    int source[] = {1, 2, 3};
    recurse(source, 3);
}