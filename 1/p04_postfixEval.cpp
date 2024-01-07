#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
            return 1;
            break;
    }
    return 0;
}

float operate(float o1, float o2, char op) {
    switch(op) {
        case '+':
            return o1 + o2;
            break;
        case '-':
            return o1 - o2;
            break;
        case '*':
            return o1 * o2;
            break;
        case '/':
            return o1/o2;
            break;
        case '$':
            return pow(o1, o2);
            break;
    }
    return -1;
}

int postFixCalc(string s) {
    int op1, op2;
    stack<int> values;
    int value;
    for(int i = 0; i < s.length(); i++) {
        if(isOperator(s[i])) {
            op1 = values.top();
            values.pop();
            op2 = values.top();
            values.pop();
            value = operate(op2, op1, s[i]);
            values.push(value);
        } else {
            values.push(s[i] - '0');
        }
    }
    return values.top();
}

int main() {
    string s;
    cout<<"Enter the postfix expression: ";
    cin>>s;
    cout<<"The value of the expression is: "<<postFixCalc(s);
    return 0;
}