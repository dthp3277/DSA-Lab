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