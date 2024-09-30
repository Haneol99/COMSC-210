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
            cout << "Movie: " << movieTiltle << endl;
            cout << setw(W15) << "Year released: " << yearReleased << endl;
            cout << setw(W15) << "Screenwriter: " << screenWriter << endl;
            cout << endl;
        }

};

int main()
{
    vector<Movie> movie;
    ifstream inFile("/Users/yeomhan-eol/COMSC210/Assignment/movie.txt");
    if (!inFile.is_open())
    {
        cout << "file is not open!" << endl;
        return 4;
    }

    return 0;
}