// name of goats:  "Buttercup", "Clover", "Daisy", "Fawn", "Hazel", "Honey", "Ivy",
// "Luna", "Misty", "Pepper", "Poppy", "Rosie", "Sage", "Willow", "Zinnia"
// color: "Butterscotch", "Cinnamon", "Fawn", "Ginger", "Honey", "Lavender", "Mocha", "Olive",
// "Peppermint", "Rose Gold", "Sandalwood", "Snowflake", "Sunbeam", "Toffee", "Walnut"

//output:
/*
Forward: 
    Senior (Yellow, 6)
    Godlike (Red, 7)
    Old (Red, 2)
    Old (Gold, 6)
    Mature (Mauve, 6)
    Teen (Gold, 10)
    Teen (White, 17)

Backward: 
    Teen (White, 17)
    Teen (Gold, 10)
    Mature (Mauve, 6)
    Old (Gold, 6)
    Old (Red, 2)
    Godlike (Red, 7)
    Senior (Yellow, 6)
*/

#include <iostream>
using namespace std;
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class Goat
{
    private:
        int age;
        string name;
        string color;
        string names[15] = {"Buttercup", "Clover", "Daisy", "Fawn", "Hazel", "Honey", "Ivy",
                        "Luna", "Misty", "Pepper", "Poppy", "Rosie", "Sage", "Willow", "Zinnia"};
        string colors[15] = {"Butterscotch", "Cinnamon", "Fawn", "Ginger", "Honey", "Lavender", "Mocha", "Olive",
                            "Peppermint", "Rose Gold", "Sandalwood", "Snowflake", "Sunbeam", "Toffee", "Walnut"};
    
    public:
        //default constructor and parameter constructor
        Goat()
        {
            age = rand() % 20 +1;
            name = names[rand() % 15];
            color = colors[rand() % 15];
        }

        Goat(int a, string b, string c)
        {
            age = a;
            name = b;
            color = c;
        }

        //setter getter
        int getAge() const
        {
            return age;
        }
        string getName() const
        {
            return name;
        }
        string getColor() const
        {
            return color;
        }
};

class DoublyLinkedList
{
private:
    struct Node
    {
        Goat data;
        Node *prev;
        Node *next;
        Node(Goat val, Node *p = nullptr, Node *n = nullptr)
        {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node *head;
    Node *tail;

public:
    // constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push_back(Goat value)
    {
        Node *newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_front(Goat value)
    {
        Node *newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() 
    {
        Node *current = head;
        if (!current)
            cout << "List is empty"<< endl;
            return;
        while (current)
        {

            cout << current->data.getName() << " (" << current->data.getColor() 
            << ", " << current->data.getAge() << ") ";
            current = current->next;
        }
        cout << endl;
    }
    void print_reverse()
    {
        Node *current = tail;
        if (!current)
            return;
        while (current)
        {
            cout << current->data.getName() << " (" << current->data.getColor() 
            << ", " << current->data.getAge() << ") ";
            current = current->prev;
        }
        cout << endl;
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
};
// Driver program
int main()
{
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % 16 + 6;
    for (int i = 0; i < size; ++i)
        list.push_back();
    cout << "List forward: ";
    list.print();
    cout << "List backward: ";
    list.print_reverse();
    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();
    return 0;
}