#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;   // data(int data type)
        Node* prev; // ptr : point to prevtious node
        Node* next; // ptr : point to next node
        // constructor: initialize data, also setting ptr(prev and next)
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head; // ptr point to head(first node)
    Node* tail; // ptr point to tail(last node)

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }  // initialize head and tail to null

    // function: insert a new node at the position(int position)
    void insert_after(int value, int position) {
        if (position < 0) { // position must be 0
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);    // make new node
        if (!head) {    // list empty -> setting new node = head and tail
            head = tail = newNode;
            return;
        }

        Node* temp = head;  // set temp as head(first node)
        for (int i = 0; i < position && temp; ++i) // for loop for traverse to position we want
            temp = temp->next; // move to next node

        if (!temp) {    // if position bigger than size of list
            cout << "Positi on exceeds list size. Node not inserted.\n";    // error message
            delete newNode; // delete node
            return;
        }

        newNode->next = temp->next; // setting next of new node as next of temp 
        newNode->prev = temp;   // setting prev of new node as temp
        if (temp->next)     // if temp has next node
            temp->next->prev = newNode; // setting prev of next as newnode
        else 
            tail = newNode; // setting tail as newnode(if temp is last node)
        temp->next = newNode;   // setting next of temp as newnode
    }

    // function: delete node which has value we got(int value)
    void delete_val(int value) {
        if (!head) return;  // if list is empty -> return

        Node* temp = head;  // setting temp as head(first node)
        
        while (temp && temp->data != value) // while loop for traverse till finding the falue
            temp = temp->next;  // move to next node

        if (!temp) return; // if we cannot find the value --> return

        if (temp->prev) //if temp has prev node 
            temp->prev->next = temp->next;  // setting next of prev as next of temp
        else
            head = temp->next;      // if temp is head -> update head

        if (temp->next) // if temp has next node 
            temp->next->prev = temp->prev;  // setting prev of next as prev of temp
        else
            tail = temp->prev; // if temp is tail -> update tail

        delete temp;    // delete node
    }

    // function: delete node at a position we got(pos)
    void delete_pos(int pos) {
        if (!head) {    // if list is empty
            cout << "List is empty." << endl;   // error message
            return; // return
        }
    
        if (pos == 1) { // if pos is first position(first node)
            pop_front();    // call pop_front
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    // function : delete first node from list
    void pop_front() {

        if (!head) {    // if the list empty
            cout << "List is empty." << endl;   // error message
            return; // return
        }

        Node * temp = head; // temp as head

        if (head->next) {   // if there is next after head
            head = head->next;  // setting head as next
            head->prev = nullptr;   // setting prev of new head to nullptr
        }
        else
            head = tail = nullptr;  // when we have only one node -> setting head and tail to nullptr
        delete temp;    // delete node (old head) 
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}