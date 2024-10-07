/*
Which linked list method should we use?
    [1] New nodes are added at the head of the linked list
    [2] New nodes are added at the tail of the linked list
    Choice: 2
Enter review rating 0-5: 4.8
Enter review comments: Oscar contender
Enter another review? Y/N: y
Enter review rating 0-5: 4.1
Enter review comments: Brilliant lead acting
Enter another review? Y/N: n
Outputting all reviews:
    > Review #1: 4.8: Oscar contender
    > Review #2: 4.1: Brilliant lead acting
    > Average: 2.96667
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    double rating;
    string comment;
    Node *next;
};

void addHead(Node*& , double , string );
void addTail(Node*& , double , string );
void outputting(Node*);

int main()
{
    Node *head = nullptr;
    int oneOrTwo;
    double mainRating;
    string mainComment;
    char anotherReview;

    cout << "Which linked list method should we use?" << endl
         << setw(5) << "" << "[1] New nodes are added at the head of the linked list" << endl
         << setw(5) << "" << "[2] New nodes are added at the tail of the linked list" << endl
         << setw(5) << "" << "Choice: ";
    cin >> oneOrTwo;

    cout << "Enter review rating 0-5: ";
    cin >> mainRating;

    cin.ignore();

    cout << "Enter review comments: ";
    getline(cin, mainComment);

    if (oneOrTwo == 1)
    {
        addHead(head, mainRating, mainComment);
    }
    else if (oneOrTwo == 2)
    {
        addTail(head, mainRating, mainComment);
    }

    cout << "Enter another review? Y/N: ";
    cin >> anotherReview;

    while (anotherReview == 'Y' || anotherReview == 'y')
    {
        cout << "Enter review rating 0-5: ";
        cin >> mainRating;

        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, mainComment);

        if (oneOrTwo == 1)
        {
            addHead(head, mainRating, mainComment);
        }
        else if (oneOrTwo == 2)
        {
            addTail(head, mainRating, mainComment);
        }

        cout << "Enter another review? Y/N: ";
        cin >> anotherReview;
    }

    // output
    outputting(head);

    return 0;
}

void addHead(Node*& head, double r, string c)
{
    Node *newNode = new Node;
        if (!head)
        {
            head = newNode;
            newNode->next = nullptr;
            newNode->rating = r;
            newNode->comment = c;
        }
        else
        {
            newNode->next = head;
            newNode->rating = r;
            newNode->comment = c;
            head = newNode;
        }
}

void addTail(Node*& head, double r, string c)
{
     Node *newNode = new Node;
        newNode->rating = r;
        newNode->comment = c;
        newNode->next = nullptr;
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
}

void outputting(Node* head)
{
    if (!head)
    {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    double total = 0;
    Node *current = head;

    while (current)
    {
        cout << setw(5) << "" << "> Review #" << count++ << ": " << current->rating << ": " << current->comment << endl;
        total += current->rating;
        current = current->next;
    }
    int i = (count -1);
    cout << setw(5) << "" << "> Average: " << total / (count-1) << endl;
}