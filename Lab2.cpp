#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

struct Color
{
    int red, green, blue;
};


int main()
{
    vector <Color> clr;
    srand(time(0));

    int n = rand() % 26 + 25;

    for(int i = 0; i< n; i++){
        Color cr;
        cr.red = rand() % 256;
        cr.green = rand() % 256;
        cr.blue = rand() % 256;
        
        clr.push_back(cr);
    }

    cout << left << setw(10) << "Color#" 
        << left << setw(10) << "R value"
        << left << setw(10) << "G value"
        << left << setw(10) << "B value" << endl;
    cout << left << setw(10) << "------"
        << left << setw(10) << "-------"
        << left << setw(10) << "-------"
        << left << setw(10) << "-------" << endl;

    for(int i = 0; i< clr.size(); i++){
        cout << left << setw(10) << i+1
        << left << setw(10) << clr[i].red
        << left << setw(10) << clr[i].green
        << left << setw(10) << clr[i].blue << endl;
    }


    return 0;
}