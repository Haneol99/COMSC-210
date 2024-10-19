#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

struct Node
{
    string data;
    Node *prev;
    Node *next;
    Node(string val, Node *p = nullptr, Node *n = nullptr)
    {
        data = val;
        prev = p;
        next = n;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addfront(const string &name)
    {
        Node *newNode = new Node(name);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addBack(const string &name)
    {
        Node *newNode = new Node(name);
        if (!tail)
        {
            head = tail = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeFront()
    {
        if (!head)
            return;
        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void removeBack()
    {
        if (!tail)
            return;
        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print()
    {
        Node *current = head;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
vector<string> fileNames(const string &);

int main()
{
    DoublyLinkedList lst;
    vector<string> name = fileNames("/Users/yeomhan-eol/names.txt");

    for (const string &n : name)
    {
        lst.addBack(n);
    }

    cout << "Store opens:\n";
    for (int i = 0; i < 5; ++i)
    {
        int randomIndex = rand() % names.size();
        cout << names[randomIndex] << " joins the line\n";
        line.addBack(names[randomIndex]);
    }
    cout << "Resulting line:\n";
    lst.print();

    for (int minute = 1; minute <= 20; ++minute)
    {
        cout << "Time step #" << minute << ":\n";

        // 40% 확률로 첫 고객 서비스
        int prob = rand() % 100 + 1;
        if (prob <= 40 && !line.isEmpty())
        {
            cout << line.getFrontName() << " is served\n";
            line.removeFront();
        }

        prob = rand() % 100 + 1;
        if (prob <= 60)
        {
            int randomIndex = rand() % names.size();
            cout << names[randomIndex] << " joins the line\n";
            line.addBack(names[randomIndex]);
        }

        prob = rand() % 100 + 1;
        if (prob <= 20 && !line.isEmpty())
        {
            cout << line.getBackName() << " exits the rear of the line\n";
            line.removeBack();
        }
        return 0;
    }

    vector<string> fileNames(const string &filename)
    {
        vector<string> names;
        ifstream inFile(filename);
        string name;
        while (inFile >> name)
        {
            names.push_back(name);
        }
        return names;
    }