#include <bits/stdc++.h>
using namespace std;

bool balancedParantheses(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
            st.push(s[i]);
        else {
            switch(s[i]) {
                case ']':
                    if(st.top() == '[')
                        st.pop();
                    else return false;
                    break;
                case '}':
                    if(st.top() == '{')
                        st.pop();
                    else return false;
                    break;
                case ')':
                    if(st.top() == '(')
                        st.pop();
                    else return false;
                    break;
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main() {
    string s = "[{(()()[((){})]}]";
    if(balancedParantheses(s)) {
        cout<<"The parantheses are balanced."<<endl;
    } else {
        cout<<"The paranthees are not balanced."<<endl;
    }
    return 0;
}