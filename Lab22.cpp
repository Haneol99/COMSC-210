// COMSC-210 | Lab 22 | Haneol Yeom
// IDE used: VS code

// name changing : delete_node() --> delete_val()
// create pop_front() : delete the head node
// create pop_back() : delete the tail node
// create delete_pos() : delete node by position. Not by value. 
//                      The method should also cover the case where 
//                      we want to delete the head or tail node.

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList();
    void push_back(int );
    void push_front(int );
    void insert_after(int, int); 
    void pop_front();
    void pop_back();
    void delete_pos(int);
    void delete_val(int );
    void print();
    void print_reverse();
    ~DoublyLinkedList();
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << endl << "driver that fully exercises these changes made to the class." << endl << endl;

    cout << "pop front : ";
    list.pop_front();
    list.print();
    cout << endl;

    cout << "pop back : ";
    list.pop_back();
    list.print();
    cout << endl;

    cout << "delete by position : ";
    list.delete_pos(3);
    list.print();
    cout << endl;

    cout << "delete by value : ";
    list.delete_val(48);
    list.print();
    cout << endl;


    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}

DoublyLinkedList::DoublyLinkedList() { head = nullptr; tail = nullptr; }

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail)  // if there's no tail, the list is empty
        head = tail = newNode;
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        }
}

void DoublyLinkedList::push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

void DoublyLinkedList::insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

void DoublyLinkedList::pop_front() {
        if(!head) return;
        Node* temp = head;
        if(temp == tail){
            head = nullptr;
            tail = nullptr;
        } else {
            head = temp -> next;
            head -> prev = nullptr;
        }
        delete temp;
    }

void DoublyLinkedList::pop_back(){
        if(!tail) return;
        Node* temp = tail;
        if(head == temp){
            head = nullptr;
            tail = nullptr;
        } else {
            tail = temp -> prev;
            tail -> next = nullptr;
        }
        delete temp;
    }

void DoublyLinkedList::delete_pos(int position){
        if(!head){
            return;
        } else if(position < 0){
            cout << "Position must be >= 0." << endl;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            return;
        } else if(position == 0){
            pop_front();
        } else if(temp == tail){
            pop_back();
        } else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

    }

void DoublyLinkedList::delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

void DoublyLinkedList::print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

void DoublyLinkedList::print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

DoublyLinkedList::~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }