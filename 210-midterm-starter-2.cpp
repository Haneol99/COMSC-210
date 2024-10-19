#include <iostream>
#include <fstream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;


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


class DoublyLinkedList {
private:
    

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void addfront(const string& name){
        Node* newNode = new Node(name);
        if(!head){
            head = tail = newNode;
        } else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void addBack(const string& name){
        Node* newNode = new Node(name);
        if(!tail){
            head = tail = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeFront(){
        if(!head) return;
        Node* temp = head;
        if(head == tail){
            head = tail = nullptr;
        } else {
            head = head -> next;
            head -> prev = nullptr;
        }
        delete temp;
    }

    void removeBack(){
        if(!tail) return;
        Node* temp = tail;
        if(head == tail){
            head = tail = nullptr;
        } else {
            tail = tail-> prev;
            tail-> next = nullptr;
        }
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
};
void fileNames(const string& filename){
        vector<string> names;
        ifstream inFile(filename);
        string name;
        while(inFile >> name){
            names.push_back(name);
        }
        return names;
}

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}
