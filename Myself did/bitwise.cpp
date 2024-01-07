#include <iostream>

using namespace std;

bool isPowerofTwo(int x) {
    return (x & (x-1)) == 0;
}

int main() {
    cout<<(7<<3);
    return 0;
}