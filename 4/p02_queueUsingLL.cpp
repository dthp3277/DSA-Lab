#include <iostream>
#include <string>


using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class Queue {
    private:
        Node<T>* head;
    public:
        Queue() {
            head = nullptr;
        }
        ~Queue() {
            Node<T>* temp;
            while(head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void enqueue(T val) {
            Node<T>* new_node = new Node<T>;
            if(!new_node) {
                throw string("Memory Overflow");
            }
            new_node->data = val;
            new_node->next = nullptr;
            if(!head) head = new_node;
            else {
                Node<T>* temp = head;
                while(temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }

        T dequeue() {
            if(!head) throw string("Queue is Empty");
            Node<T>* temp = head;
            head = head->next;
            T val = temp->data;
            delete temp;
            return val;
        }
};

int main() {
    Queue<string> q;
    try {
        q.enqueue("Dhiraj");
        q.enqueue("Bishal");
        q.enqueue("bajre");
        q.enqueue("Biraj");
        cout<<q.dequeue()<<" is dequeued from the queue"<<endl;
        cout<<q.dequeue()<<" is dequeued from the queue"<<endl;
        cout<<q.dequeue()<<" is dequeued from the queue"<<endl;
        cout<<q.dequeue()<<" is dequeued from the queue"<<endl;
    } catch(string error) {
        cerr<<error<<endl;
        exit(-1);
    }
    return 0;
}