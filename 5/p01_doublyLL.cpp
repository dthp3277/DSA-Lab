#include <iostream>
#include <string>

using namespace std;

template<typename T> 
struct DLLNode {
    T data;
    DLLNode* prev;
    DLLNode* next;
};


//this is a doubly linked list implementation
template<typename T>
class DoublyLinkedList {
    private:
        DLLNode<T>* head;
    public:
        DoublyLinkedList() {
            head = nullptr;
        }

        ~DoublyLinkedList() {
            DLLNode<T>* temp;
            while(temp != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void printList() {
            DLLNode<T>* temp = head;
            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void insertAtBeginning(T val) {
            DLLNode<T>* new_node = new DLLNode<T>;
            if(!new_node) throw string("Memory Overflow");
            new_node->prev = nullptr;
            new_node->next = nullptr;
            new_node->data = val;
            if(!head) head = new_node;
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }

        void insertAtEnd(T val) {
            DLLNode<T>* new_node = new DLLNode<T>;
            if(!new_node) throw string("Memory Overflow");
            new_node->prev = nullptr;
            new_node->next = nullptr;
            new_node->data = val;
            if(!head) head = new_node;
            else {
                DLLNode<T>* temp = head;
                while(temp->next) {
                    temp = temp->next;
                }
                temp->next = new_node;
                new_node->prev = temp;
            }
        }

        void insertAfter(T node_val, T val) {
            DLLNode<T>* new_node = new DLLNode<T>;
            new_node->prev = nullptr;
            new_node->next = nullptr;
            new_node->data = val;
            if(!head) head = new_node;
            else {
                DLLNode<T>* temp = head;
                while(temp->data != node_val) {
                    temp = temp->next;
                }
                if(!temp) throw string("Node not found!");
                new_node->next = temp->next;
                new_node->prev = temp;
                temp->next->prev = new_node;
                temp->next = new_node;
            }
        }

        void insertBefore(T node_val, T val) {
            DLLNode<T>* new_node = new DLLNode<T>;
            new_node->prev = nullptr;
            new_node->next = nullptr;
            new_node->data = val;
            if(!head) head = new_node;
            else {
                DLLNode<T>* temp = head;
                while(temp->data != node_val) {
                    temp = temp->next;
                }
                if(!temp) throw string("Node not found!");
                new_node->next = temp;
                new_node->prev = temp->prev;
                if(temp->prev)
                temp->prev->next = new_node;
                temp->prev = new_node;
            }
        }

        void deleteAtBeginning() {
            DLLNode<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        void deleteAtEnd() {
            DLLNode<T>* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            DLLNode<T>* temp2 = temp;
            temp->prev->next = nullptr;
            delete temp;
        }

        void deleteAfter(T node_val) {
            DLLNode<T>* temp = head;
            while(temp->data != node_val) {
                temp = temp->next;
            }
            DLLNode<T>* temp2 = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete temp2;
        }

        void deleteBefore(T node_val) {
            DLLNode<T>* temp = head;
            while(temp->data != node_val) {
                temp = temp->next;
            }
            DLLNode<T>* temp2 = temp->prev;
            temp->prev = temp->prev->prev;
            temp->prev->next = temp;
            delete temp2;
        }
};

int main() {
    DoublyLinkedList<int> x;
    try {
        x.insertAtBeginning(1);
        x.insertAtBeginning(2);
        x.insertAtBeginning(5);
        x.insertAtEnd(6);
        x.insertAtEnd(8);
        x.insertAfter(6, 9);
        x.insertBefore(9, 10);
        x.insertBefore(10, 3);
        x.deleteAfter(3);
        x.deleteAfter(3);
        x.deleteBefore(3);
        x.printList();
    } catch(string error) {
        cerr<<error<<endl;
        exit(-1);
    }

    return 0;
}