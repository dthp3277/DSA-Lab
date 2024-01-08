#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

template <typename T> //circular banaune eslai

class Deque {
    private:
        int front, end;
        int arr[MAX_SIZE];
        int incCircular(int a) {
            a = (a + 1) % MAX_SIZE;
            return a;
        }
        int decCircular(int a) {
            a = a - 1;
            if(a < 0) a += MAX_SIZE;
            return a;
        }
    public:
        Deque() {
            front = end = -1;
        }

        void addBegin(T val) {
            if(isFull()) {
                cerr<<"Queue Overflow!"<<endl;
                exit(0);
            } else {
                if(front == -1 && end == -1) {
                    front = end = 0;
                } else 
                    front = decCircular(front);
            }
            arr[front] = val;
        }

        void addEnd(T val) {
            if(isFull()) {
                cerr<<"Queue Overflow!"<<endl;
                exit(-1);
            } else {
                if(front == -1 && end == -1) {
                    front = end = 0;
                } else 
                    end = incCircular(end);
            }
            arr[end] = val;
        }

        T removeBegin() {
            T value;
            if(isEmpty()) {
                cerr<<"Queue Undeflow!"<<endl;
            } else {
                value = arr[front];
                front = incCircular(front);
            }
            return value;
        }

        T removeEnd() {
            T value;
            if(isEmpty()) {
                cerr<<"Queue Undeflow!"<<endl;
            } else {
                value = arr[end];
                end = decCircular(end);
            }
            return value;
        }

        bool isFull() {
            if(front == incCircular(end)) return true;
            return false;
        }

        bool isEmpty() {
            if(front == -1 && end == -1) return true;
            return false;
        }

        void printQueue() {
            int i;
            for(i = front; i != end; i = incCircular(i)) {
                cout<<arr[i]<<' ';
            }
            cout<<arr[i];
        }
        void status() {
            cout<<"Front = "<<front<<"back = "<<end<<endl;
        }
};

int main() {
    Deque<int> q;
    q.addBegin(5);
    q.addBegin(6);
    q.addEnd(7);
    
    q.addBegin(5);
    q.addEnd(8);
    q.removeEnd();
    q.removeBegin();
    q.printQueue();
    return 0;
}