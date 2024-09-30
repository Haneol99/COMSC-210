#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const int W15 = 15;

class Movie
{
    private:
        string movieTiltle;
        int yearReleased;
        string screenWriter;
    
    public:
        string getTitle() {return movieTiltle; }
        void setTitle(string t) {movieTiltle = t;}
        int getYear() const {return yearReleased;}
        void setYear(int y) {yearReleased = y;}
        string getwriter() {return screenWriter;}
        void setWriter(string w) {screenWriter = w;}

        void print() 
        {
            
        }






};

int main()
{

    return 0;
}