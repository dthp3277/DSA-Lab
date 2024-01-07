#include <bits/stdc++.h>
using namespace std;
//postfix evaluation

bool isOperator(char o) {
    if(o == '+' || o == '-' || o == '$' || o == '/' || o == '*') return true;
    return false;
}

float evaluate(int op1, int op2, char op) {
    float value;
    switch(op) {
        case '+':
            value = op1+op2;
            break;
        case '-':
            value = op1-op2;
            break;
        case '*':
            value = op1*op2;
            break;
        case '/':
            value = (float)op1/op2;
            break;
        case '$':
            value = pow(op1, op2);
            break;
    }
    return value;
}

bool isDigit(char o) {
    if(o >= '0' && o <= '9') return true;
    return false;
}

int value(string postfix) {
    stack<int> st;
    int value;
    char symb;
    for(int i = 0; i < postfix.length(); i++) {
        symb = postfix[i];
        if(isDigit(symb)) {
            st.push(symb - '0');
        } else if(isOperator(symb)) {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res = evaluate(op1, op2, symb);
            st.push(res);
        }
    }
    return st.top();
}



int main() {
    string exp = "623+-382/+*2$3+";
    cout<<value(exp);
    return 0;
}