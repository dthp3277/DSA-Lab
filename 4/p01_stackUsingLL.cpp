#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class Stack {
    private:
        Node<T>* head;
    public:
        Stack() {
            head = nullptr;
        }
        ~Stack() {
            Node<T>* temp;
            while(head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void push(T val) {
            Node<T>* new_node = new Node<T>;
            if(!new_node) {
                throw string("Memory Overflow");
            }
            new_node->data = val;
            new_node->next = nullptr;
            if(!head) head = new_node;
            else {
                new_node->next = head;
                head = new_node;
            }
        }

        T top() {
            if(head) return head->data;
            throw string("Stack is Empty");
        }

        T pop() {
            if(!head) throw string("Stack is Empty");
            Node<T>* temp = head;
            head = head->next;
            T val = temp->data;
            delete temp;
            return val;
        }
};

int main() {
    Stack<string> st;
    try {
        st.push("Gannu");
        st.push("Biggy");
        st.push("Bishal");
        st.push("Bajre");
        cout<<st.pop()<<endl;
        cout<<st.pop()<<endl;
        cout<<st.pop()<<endl;
    } catch(string error) {
        cerr<<error<<endl;
        exit(-1);
    }
    return 0;
}