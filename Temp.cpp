#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 5;

void incCircular(int& a) {
            a = (a + 1) % MAX_SIZE;
        }
        void decCircular(int& a) {
            a = a - 1;
            if(a < 0) a += MAX_SIZE;
        }

int main() {
    int a = 0;
    decCircular(a);
    cout<<a;
    return 0;
}