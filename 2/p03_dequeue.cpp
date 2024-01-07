#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

template <typename T>
class Deque {
    private:
        int front, end;
        int arr[MAX_SIZE];
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
                    front = end = MAX_SIZE / 2;
                } else 
                    front -= 1;
            }
            arr[front] = val;
        }

        void addEnd() {
            if(isFull()) {
                cerr<<"Queue Overflow!"<<endl;
                exit(-1);
            } else {
                if(front == -1 && end == -1) {
                    front = end = MAX_SIZE /2;
                } else 
                    end += 1;
            }
            arr[end] = val;
        }

        int removeBegin() {
            if(isEmpty()) {
                cerr<<"Queue Undeflow!"<<endl;
            }
        }

        int removeEnd() {
            if(isEmpty()) {
                cerr<<"Queue Undeflow!"<<endl;
            }
        }

        bool isFull() {

        }

        bool isEmpty() {

        }
};