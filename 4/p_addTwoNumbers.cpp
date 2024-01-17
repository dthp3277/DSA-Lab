#include <iostream>
#include <string>
#include <cmath>


struct Node {
    int digit;
    Node* next;
};

class Number {
    private:
        Node* head;
    public:
        Number() {
            head = nullptr;
        }
        Number(int val) {
            head = nullptr;
            while(val != 0) {
                this->addDigit(val % 10);
                val /= 10;
            }
        }
        void addDigit(int val) {
            Node* new_node = new Node;
            if(!new_node) throw(std::string("Memory Overflow!"));
            new_node->digit = val;
            new_node->next = nullptr;
            if(!head) {
                head = new_node;
            } else {
                Node* temp = head;
                while(temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }

        Number add(Number n2) {
            Node* head1 = this->head;
            Node* head2 = n2.head;
            Number result;
            int carry = 0, sum;
            while(true) {
                std::cout<<carry<<std::endl;
                if(carry == 0 && head1 == nullptr && head2 == nullptr) break;
                sum = (head1 ? head1->digit : 0) + (head2 ? head2->digit : 0) + carry;
                if(sum > 9)  {
                    result.addDigit(sum - 10);
                    sum/=10;
                    carry = sum;
                } else {
                    result.addDigit(sum);
                    carry = 0;
                }
                result.printNumber();
                if(head1) head1 = head1->next;
                if(head2) head2 = head2->next;
            } 
            return result;    
        }

        void printNumber() {
            int num = 0;
            Node* temp = head;
            int c = 0;
            while(temp!=nullptr) {
                num = temp->digit * pow(10, c) + num;
                temp = temp->next;
                c++;
            }
            std::cout<<num<<std::endl;
        }
};  

int main() {
    try {
        Number a(99999);
        Number b(3326);
        Number c = a.add(b);
        std::cout<<"The result is: ";
        c.printNumber();
    } catch(std::string error) {
        std::cerr<<error<<std::endl;
        exit(-1);
    }
    return 0;
}