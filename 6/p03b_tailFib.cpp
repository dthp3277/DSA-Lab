#include <iostream>
using namespace std;

long tailFib(int n, int curr = 0, int next = 1) {
    if(n == 0) return curr;
    return tailFib(n - 1, next, curr + next);
}

int main() {
    for(int i = 0; i < 10; i++) {
        cout<<"fib("<<i<<")"<<tailFib(i)<<endl;
    }
    return 0;
}