#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

template <typename T>
class CircularQueue {
    private:
        int front, rear;
        T arr[MAX_SIZE];
    public:
        CircularQueue() {
            front = rear = -1;
        }
        void enqueue(T val) {
            if(front == -1 && rear == -1) {
                front = rear = 0;
            } else {
               if(isFull()) {
                    cerr<<"Error! Queue Overflow."<<endl;
                    exit(-2);
               } else {
                    rear = (rear + 1) % MAX_SIZE;
               }
            }
            arr[rear] = val;
        }

        T dequeue() {
            T val;
            if(isEmpty()) {
                cerr<<"Error! Queue underflow."<<endl;
                exit(-1);
            } else {
                val = arr[front];
                if(front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % MAX_SIZE;
                }
            }
            return val;
        }

        bool isFull() {
            return (front == (rear + 1) % MAX_SIZE);
        }

        bool isEmpty() {
            return  (front == -1 && rear == -1);
        }
};

int main() {
    CircularQueue<int> x;
    x.enqueue(5);
    x.enqueue(6);
    x.enqueue(7);
    x.enqueue(8);
    x.enqueue(9);
    x.dequeue();
    x.enqueue(10);
    while(!x.isEmpty()) {
        cout<<x.dequeue()<<" is removed from thee queue"<<endl;
    }
}