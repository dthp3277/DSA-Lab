#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

template <typename T>
class Stack {
    private:
        T arr[MAX_SIZE];
        int top;
    public:
        Stack() {
            top = -1;//stack initially empty
        }       
        void push(T val) {
            if(top == MAX_SIZE - 1)  {
                cerr<<"Cannot push, Stack is full.";
                exit(0);
            } else 
                arr[++top] = val;
        }

        T pop() {
            if(top == -1) {
                cerr<<"Cannot pop, Stack is empty";
                exit(0);
            } else 
               return arr[top--];
        }
        bool isEmpty() {
            if(top == -1) return true;
            return false;
        }
        bool isFull() {
            if(top == MAX_SIZE - 1) return true;
            return false;
        }
        T seek() {
            if(top == -1) {
                cerr<<"Stack is empty";
                exit(0);
            }
            return arr[top];
        }
        int TOP() {
            return top;
        }
};

int main() {
    Stack<int> st;
    int c;
    int val;
    bool flag = false;
    do {
        cout<<"Stack: What do you want to do? "<<endl;
        cout<<"1: push 2:pop -1: exit"<<endl;
        cin>>c;
        switch(c) {
            case 1: 
                cout<<"Enter the value to push: "<<endl;
                cin>>val;
                st.push(val);
                cout<<val<<" is pushed in the stack."<<endl;
                break;
            case 2: 
                cout<<st.pop()<<" is popped from the stack"<<endl;
                break;
            case -1: 
                flag = true;
                 break;
        }
    } while(!flag);
    
    return 0;
}