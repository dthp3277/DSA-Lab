#include <iostream>
using namespace std;

long long int fact(int n, int acc = 1) {
    if(n == 1) return acc;
    return fact(n - 1, n * acc);
}

long long int factorial(int n) { return fact(n, 1); }

int main() {
    cout<<"5! = "<<factorial(5);
}