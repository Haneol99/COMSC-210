// Number of absences for each of the 30 students in a class
// find The nuber of most absences
// find The number of fewest absences
// find total class absences
// get the avg number of absence

#include <iostream>
#include <algorithm> // for sort(), find()
#include <numeric>   // for accumulate()
#include <fstream>   // for ifstream
using namespace std;
const int SIZE = 30;

int main()
{
    array<int, SIZE> class1 = {};

    ofstream outFile("file.txt");

    if (outFile)
    {
        for (int i = 0; i < SIZE; i++)
        {
            outFile << i + 1 << endl;
        }
    }
    else
    {
        cout << "File is not opened" << endl;
        return 4;
    }
    outFile.close();

    ifstream inFile("/Users/yeomhan-eol/COMSC210/Assignment/file.txt");
    if (inFile.is_open())
    {
        for (int i = 0; i < SIZE; i++)
        {
            inFile >> class1[i];
        }
    }

    inFile.close();

    cout << "Number of Students in a class: " << class1.size() << endl;

    cout << "-------Number of Absences-------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "student " << i + 1 << ": " << class1[i] << endl;
    }

    cout << "The number of absence of 15th student: ";
    cout << class1.at(15 - 1) << endl;


    cout << "The most number of absence: " << *max_element(class1.begin(), class1.end()) << endl;

    cout << "The fewest number of absence: " << *min_element(class1.begin(), class1.end()) << endl;

    cout << "The total absence of class1: ";
    int total = accumulate(class1.begin(), class1.end(), 0);
    cout << total << endl;

    cout << "The average number of absence of class1: ";
    double avgAbsence = static_cast<double>(total) / class1.size();
    cout << avgAbsence << endl;

    cout << "----- new year new class -----" << endl;
    fill(class1.begin(), class1.end(), 0);
    for (int i = 0; i < class1.size(); i++)
    {
        cout << "student " << i + 1 << ": " << class1[i] << endl;
    }

    return 0;
}