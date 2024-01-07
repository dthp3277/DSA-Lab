#include <bits/stdc++.h>

using namespace std;

int prec(char c) {
    switch(c) {
        case '^':
            return 3;
            break;
        case '/':
        case '*':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            return -1;
    }
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;
    char c;

    for(int i = 0; i < s.length(); i++) {
        c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) { //if it is an operand
            result += c;
        } else {
            if(c == '(')
                st.push(c);
            else if(c == ')') {
                while(st.top() != '(') {
                    result+=st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while(!st.empty() && (prec(s[i]) <= prec(st.top()))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }

    while(!st.empty()) {
        result+=st.top();
        st.pop();
    }
    return result;
}

int main() {
    string infixExp;
    cout<<"Enter the infix expression: ";
    cin>>infixExp;
    cout<<infixToPostfix(infixExp);
    return 0;
}