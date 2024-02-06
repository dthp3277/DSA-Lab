#include <iostream>
using namespace std;

long long int fact(int n) {
    return (n == 0) ? 1 : n * fact(n-1);
}

int main() {
    cout<<"5! = "<<fact(5);
}