#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 50;

template <typename T>
class Queue {
    private:
        T arr[MAX_SIZE];
        int front;
        int rear;
    public:
        Queue() {
            front = -1;
            rear = -1;
        }

        void enqueue(T data) {
            if((front == -1) && (rear == -1)) {
                front = rear = 0;
            } else if(rear == MAX_SIZE - 1) {
                cerr<<"Error, Queue Overflow!"<<endl;
                exit(-1);
            } else {
                rear = rear+1;
            }
            arr[rear] = data;
        }

        T dequeue() {
            T val;
            if(front == -1 && rear == -1) {
                cerr<<"Error, Queue Underflow!"<<endl;
                exit(0);
            } else  {
                val = arr[front];
                if(front == rear) {
                    front = rear = -1;
                } else {
                    front = front + 1;
                }
            }
            return val;
        }
};

int main() {
    Queue<string> q;
    q.enqueue("Biggy");
    q.enqueue("Bishal");
    q.enqueue("Lol");
    q.enqueue("Bajre");
    q.enqueue("Dhiraj");
    for(int i = 0; i < 5; i++) {
        cout<<q.dequeue()<<" is dequeued from the queue. "<<endl;
    }
    return 0;
}