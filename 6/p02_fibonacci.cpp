#include <iostream>
using namespace std;

long fib(int n) {
    return (n == 0) ? 0 : ( (n == 1) ? 1 : fib(n-1) + fib(n-2));
}

int main() {
    for(int i = 0; i < 10; i++) {
        cout<<"fib("<<i<<")"<<fib(i)<<endl;
    }
    return 0;
}