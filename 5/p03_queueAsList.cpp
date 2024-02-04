#include <iostream>
#include <string>
using namespace std;

const int NUMNODES = 50;

template <typename T>
class Queue {
    private:
        struct Node {
            T data;
            int next;
        };
        Node nodes[NUMNODES];
        int avail, head, tail;
    public:
        Queue() {
            avail = 0;
            head = tail = -1;
            for(int i = 0; i < NUMNODES - 1; i++) {
                nodes[i].next = i + 1;
            }
            nodes[NUMNODES - 1].next = -1;
        }

        void printList() {
            int temp = head;
            while(temp != -1) {
                cout<<nodes[temp].data<<" ";
                temp = nodes[temp].next;
            }
        }

        //adds to the end of the list
        void enqueue(T val) {
            if(avail == -1) throw string("Queue is full!");
            int newNode = avail;
            avail = nodes[newNode].next;

            nodes[newNode].data = val;
            nodes[newNode].next = -1;

            cout<<val<<" is enqueued."<<endl;

            if(head == -1) head = tail = newNode;
            else {
                nodes[tail].next = newNode;
                tail = newNode;
            }
        }

        T dequeue() {
            if(head == -1) throw string("Queue is empty");
            
            T val = nodes[head].data;
            int temp = head;
            head = nodes[head].next;

            nodes[temp].next = avail;
            avail = temp;

            if(head == -1) tail = -1;
            cout<<val<<" is dequeued."<<endl;;
            return val;
        }
};


int main() {
    try {
        Queue<float> x;
        x.enqueue(5.6);
        x.enqueue(6.7);
        x.enqueue(9.8);
        x.enqueue(10.7);
        x.enqueue(6.6);
        x.dequeue();
        x.dequeue();
        x.dequeue();
        x.dequeue();
        x.dequeue();
        x.printList();
    } catch(string error) {
        cerr<<error<<endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}