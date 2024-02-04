#include <iostream>
#include <string>
using namespace std;

const int NUMNODES = 50;

template <typename T>
class StaticList {
    private:
        struct Node {
            T data;
            int next;
        };
        Node nodes[NUMNODES];
        int avail, head, tail;
    public:
        StaticList() {
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

        //adds to the beginning of the list
        void addBeginning(T val) {
            if(avail == -1) throw string("List is Full!");
            int newNode = avail;
            avail = nodes[newNode].next;
            
            nodes[newNode].data = val;
            nodes[newNode].next = head;
            head = newNode;

            if(tail == -1) tail = newNode;
        }

        //adds to the end of the list
        void addEnd(T val) {
            if(avail == -1) throw string("List is full!");
            int newNode = avail;
            avail = nodes[newNode].next;

            nodes[newNode].data = val;
            nodes[newNode].next = -1;

            if(head == -1) head = tail = newNode;
            else {
                nodes[tail].next = newNode;
                tail = newNode;
            }
        }

        void insertAfter(T val, T node_val) {
            if(avail == -1) throw string("List is full!");
            int newNode = avail;
            avail = nodes[newNode].next;

            nodes[newNode].data = val;
            nodes[newNode].next = -1;

            if(head == -1) head = tail = newNode;
            else {
                int temp = head;
                while(nodes[temp].data != node_val) {
                    temp = nodes[temp].next;
                }
                nodes[newNode].next = nodes[temp].next;
                nodes[temp].next = newNode;
            }
        }

        T deleteBeginning() {
            if(head == -1) throw string("List is empty");
            
            T val = nodes[head].data;
            int temp = head;
            head = nodes[head].next;

            nodes[temp].next = avail;
            avail = temp;

            if(head == -1) tail = -1;
            return val;
        }

        T deleteEnd() {
            if(head == -1) throw string("List is empty!");

            T val = nodes[tail].data;
            int temp = tail;
            int temp1 = head;
            while(nodes[temp1].next != tail) temp1 = nodes[temp1].next;
            tail = temp1;
            nodes[tail].next = -1;

            nodes[temp].next = avail;
            avail = temp;
            return val;
        }

        T deleteAfter(T node_val) {
            if(head == -1) throw string("List is empty!");

            int temp = head;
            while(nodes[temp].data != node_val) temp = nodes[temp].next;
            T val = nodes[nodes[temp].next].data;
            int temp2 = nodes[temp].next;
            nodes[temp].next = nodes[nodes[temp].next].next;

            nodes[temp2].next = avail;
            avail = temp2;
            return val;
        }
};

int main() {
    try {
        StaticList<int> x;
        x.addBeginning(5);
        x.addBeginning(6);
        x.addBeginning(7);
        x.insertAfter(8, 6);
        x.addEnd(10);
        x.deleteEnd();
        x.deleteAfter(6);
        x.printList();
    } catch(string error) {
        cerr<<error<<endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}