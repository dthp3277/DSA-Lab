#include <iostream>
using namespace std;

void TOH(int n, char source, char aux, char dest) {
    if(n == 0) return;
    TOH(n - 1, source, dest, aux);
    cout<<n<<" : "<<source<<" -> "<<dest<<"\n";
    TOH(n - 1, aux, source, dest);
    return;
}

int main() {
    TOH(5, 'A', 'B', 'C');
    return 0;
}