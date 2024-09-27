// AVG changes in baseball players(batter)' first 3 years

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int YEARS = 3;

struct Player
{
    string name; // name of player
    int age;     // age of player
    double *avg; //Pointer to a dynamic array that will store the three years of grades.

    // Destructor
    ~Player()   
    {
        if(avg){
            delete[] avg;
        }
        avg = nullptr;
    }

};

void inputPlayer(Player *);
void printPlayer(Player *);


int main()
{
    // get number of players
    int nop = 0;
    cout << "Number of Player: ";
    cin >> nop;
    cin.ignore();   //Remove remaining newline characters from the input buffer.

    Player *players = new Player[nop];  //// Create a dynamic array equal to the number of players entered
    for(int i = 0; i< nop; i++){
        inputPlayer(&players[i]);
    }
    for(int i = 0; i< nop; i++){
        printPlayer(&players[i]);
    }

    delete[] players;   // delete the dynamically allocated players array

    return 0;
}

void inputPlayer(Player *p)
{
    static int Nplyr = 1;   // static variable to track player number -> 
                            //Initialized to 1 only when first called and remains thereafter
    cout << "Input data for Player #" << Nplyr << ": " << endl;
    cout << "name: ";
    getline(cin, p -> name);
    cout << "age: ";
    cin >> p->age;
    p->avg = new double[YEARS]; //Create a dynamic array to store grades for 3 years
    for(int i = 0; i< YEARS; i++){
        cout << "Year " << i+1 << " AVG[ex) 0.389)]: ";
        cin >> p->avg[i];
    }
    cin.ignore();   //Remove remaining newline characters from the input buffer.
    cout << endl;
    Nplyr++;
}

void printPlayer(Player *p)
{
    cout << "--AVG changes first 3 years--" << endl;
    cout << "Name: " << p->name << endl;
    cout << "Age: " << p->age << endl;
    cout << fixed << setprecision(3);   // To output up to 3 decimal places
    for(int i = 0; i< YEARS; i++){
        cout << "Year " << i+1 <<": " <<p->avg[i] << endl;
    }
    cout << endl;
}