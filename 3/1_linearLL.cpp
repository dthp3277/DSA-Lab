#include <iostream>
#include <string>

struct Node { //linear singly linked list node
    int data;
    Node* next;
};

void printList(Node* ptr) {
    while(ptr != NULL) {
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

void insertBeginning(Node* &head, int val) {
    Node* new_node = new Node;
    if(!new_node) {
        throw std::string("OVERFLOW OF MEMORY!");
    }
    new_node->data = val;
    new_node->next = NULL;
    if(!head) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

void insertEnd(Node* &head, int val) {
    Node* new_node = new Node;
    if(!new_node) {
        throw std::string("OVERFLOW OF MEMORY!");
    }
    new_node->data = val;
    new_node->next = NULL;
    if(!head) 
        head = new_node;
    else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insertAfter(Node* &head, int val, int node_val) {
    Node* new_node = new Node;
    if(!new_node) {
        throw std::string("OVERFLOW OF MEMORY!");
    }
    new_node->data = val;
    new_node->next = NULL;
    if(!head) 
        head = new_node;
    else {
        Node* temp = head;
        while(temp->data != node_val) {
            temp = temp->next;
        }
        if(temp->data != node_val && temp->next == NULL) {
            throw std::string("NODE NOT FOUND!");
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void insertBefore(Node* &head, int val, int node_val) {
    Node* new_node = new Node;
    if(!new_node) {
        throw std::string("OVERFLOW OF MEMORY!");
    }
    new_node->data = val;
    new_node->next = NULL;
    if(!head) 
        head = new_node;
    else {
        Node* temp = head;
        while(temp->next->data != node_val && temp->next->next != NULL) {
            temp = temp->next;
        }
        if(temp->next->data != node_val && temp->next->next == NULL) {
            throw std::string("NODE NOT FOUND!");
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void deleteBeginning(Node* &head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd(Node* &head) {
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteAfter(Node* &head, int node_val) {
    Node* temp = head;
    while(temp->data != node_val && temp->next != NULL) {
            temp = temp->next;
    }
    if(temp->data != node_val && temp->next == NULL) {
        throw std::string("NODE NOT FOUND!");
    }
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

void deleteBefore(Node* &head, int node_val) {
    Node* temp = head;
    while(temp->next->next->data != node_val) {
        temp = temp->next;
    }
    if(temp == NULL) throw std::string("NODE NOT FOUND!");
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

int main() {
    Node* temp = new Node;
    Node* head = temp;
    int i;
    for(i = 5; i < 12; i++) {
        temp->data = i;
        temp->next = new Node;
        temp = temp->next;
    }
    temp->data = i;
    temp->next = NULL;
    try {
        insertBeginning(head, 69);
        insertBeginning(head, 77);
        insertEnd(head, 778);
        insertEnd(head, 779);
        insertBeginning(head, 55);
        insertAfter(head, 69, 8);
        insertAfter(head, 45, 6);
        deleteBeginning(head);
        deleteBeginning(head);
        deleteEnd(head);
        deleteEnd(head);
        deleteAfter(head, 66);
        deleteBefore(head, 9);
    } catch(std::string error) {
        std::cerr<<error;
        exit(0);
    }
    printList(head);
    return 0;
}