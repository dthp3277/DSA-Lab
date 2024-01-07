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
            return o1 / o2;
            break;
        case '^':
            return pow(o1, o2);
            break;
        default:
            return 0;
    }
    return 0;
}

float prefixCalc(string s) {
    stack<float> values;
    float op1, op2, value;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(isOperator(s[i])) {
            op1 = values.top();
            values.pop();
            op2 = values.top();
            values.pop();
            value = operate(op1, op2, s[i]);
            values.push(value);
        } else {
            values.push(s[i] - '0');
        }
    } 
    return values.top();
}

int main() {
    string s;
    cout<<"Enter the prefix expression: ";
    cin>>s;
    cout<<prefixCalc(s);
    return 0;
}