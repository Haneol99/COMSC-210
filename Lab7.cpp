#include <iostream>
#include <string>

using namespace std;

string *reverse(string *, int);

int main()
{
    const int SIZE = 5;
    string names[SIZE] = {"Janet", "Jeffe", "Jin", "Joe", "Junio"};
    string *names2 = nullptr;
    names2 = new string[SIZE];

    for(int i = 0; i< SIZE; i++){
        names2[i] = names[i];
    }


    cout << "Original array: ";
    for(int i = 0; i< SIZE; i++){
        cout << names[i] << " ";
    } cout << endl;


    reverse(names2, SIZE);
    cout << "Reversed: ";
    for(int i = 0; i<SIZE; i++){
        cout << names2[i] << " ";
    } cout << endl;
    

    return 0;
}

string *reverse(string *s, int size)
{
    string box;
    for(int i = 0; i< size/2; i++){
        box = s[i];
        int j = size - (i+1);
        s[i] = s[j];
        s[j] = box;
    }

    return s;
}