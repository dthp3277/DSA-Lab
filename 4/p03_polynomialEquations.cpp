#include <iostream>

struct Node {
    int coeff;
    int exp;
    Node* next;
};

class PolynomialEquation {
    private:
        Node* head;
    public:
        PolynomialEquation() {
            head = nullptr;
        }
        void displayEquation() {
            if(!head) return;
            Node* temp = head;
            while(temp != nullptr) {
                std::cout<<temp->coeff;
                if(temp->exp == 0) return;
                std::cout<<"x";
                if(temp->exp != 1) {
                    std::cout<<"^"<<temp->exp;
                }
                std::cout<<" + ";
                temp = temp->next;
            }
        }

        bool isEmpty() const {
            return head == nullptr;
        }

        void insert(int _coeff, int _exp) {
            Node* term = new Node;
            if(!term) throw std::string("Memory overflow");
            term->coeff = _coeff;
            term->exp = _exp;
            term->next = nullptr;
            if(!head) head = term;
            else if(head->exp < _exp) {
                term->next = head;
                head = term;
            } else {
                Node* temp = head;
                while(temp->next != nullptr && temp->next->exp >= _exp) {
                    temp = temp->next;
                }
                if(temp->exp == _exp) {
                    temp->coeff += _coeff;
                    delete term;
                    return;
                }
                term->next = temp->next;
                temp->next = term;
            } 
        }

        PolynomialEquation add(const PolynomialEquation& p2) {
            PolynomialEquation result;
            Node* head1 = this->head;
            Node* head2 = p2.head;
            while(head1 != nullptr || head2 != nullptr) {
                if(head1->exp == head2->exp) {
                    result.insert(head1->coeff + head2->coeff, head1->exp);
                    head1 = head1->next;
                    head2 = head2->next;
                } else if(head1->exp > head2->exp) {
                    result.insert(head1->coeff, head1->exp);
                    head1 = head1->next;
                } else if(head1->exp < head2->exp) {
                    result.insert(head2->coeff, head2->exp);
                    head2 = head2->next;
                }
            }
            if(!head1) {
                while(head2 != nullptr) {
                    result.insert(head2->coeff, head2->exp);
                    head2 = head2->next;
                }
            }
            if(!head2) {
                while(head1 != nullptr) {
                    result.insert(head1->coeff, head1->exp);
                    head1 = head2->next;
                }
            }
            return result;
        }
};

int main() {
    PolynomialEquation a, b, c;
    try {
        a.insert(5, 3);
        a.insert(3, 2);
        a.insert(6, 1);
        a.insert(9, 0);
        b.insert(3, 3);
        b.insert(2, 1);
        b.insert(3, 0);
        c = a.add(b);
        std::cout<<"A: ";
        a.displayEquation();
        std::cout<<std::endl<<"B: ";
        b.displayEquation();
        std::cout<<std::endl<<"Result: ";
        c.displayEquation();
    } catch(std::string error) {
        std::cerr<<error<<std::endl;
        exit(-1);
    }
    return 0;
}