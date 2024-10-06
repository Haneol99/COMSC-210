    // while (anotherReview == 'Y' || anotherReview == 'y')
    // {
    //     cout << "Enter review rating 0-5: ";
    //     cin >> mainRating;

    //     cin.ignore();

    //     cout << "Enter review comments: ";
    //     getline(cin, mainComment);

    //     if (oneOrTwo == 1)
    //     {
    //         Node *newNode = new Node;
    //         if (!head)
    //         {
    //             head = newNode;
    //             newNode->next = nullptr;
    //             newNode->rating = mainRating;
    //             newNode->comment = mainComment;
    //         }
    //         else
    //         {
    //             newNode->next = head;
    //             newNode->rating = mainRating;
    //             newNode->comment = mainComment;
    //             head = newNode;
    //         }
    //     }
    //     else if (oneOrTwo == 2)
    //     {
    //         Node *newNode = new Node;
    //         newNode->rating = mainRating;
    //         newNode->comment = mainComment;
    //         newNode->next = nullptr;
    //         if (!head)
    //         {
    //             head = newNode;
    //         }
    //         else
    //         {
    //             Node *temp = head;
    //             while (temp->next != nullptr)
    //             {
    //                 temp = temp->next;
    //             }
    //             temp->next = newNode;
    //         }
    //     }
    //     cout << "Enter another review? Y/N: ";
    //     cin >> anotherReview;
    // }