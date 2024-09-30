#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const int W20 = 20;

class Movie
{
    private:
        string movieTiltle;
        int yearReleased;
        string screenWriter;
    
    public:
        //string getTitle() {return movieTiltle; }
        void setTitle(string t) {movieTiltle = t;}
        //int getYear() const {return yearReleased;}
        void setYear(int y) {yearReleased = y;}
        //string getwriter() {return screenWriter;}
        void setWriter(string w) {screenWriter = w;}

        void print() 
        {
            cout << "Movie: " << movieTiltle << endl;
            cout << setw(W20) << "Year released: " << yearReleased << endl;
            cout << setw(W20) << "Screenwriter: " << screenWriter << endl;
            cout << endl;
        }

};

int main()
{
    vector<Movie> movie;
    ifstream inFile("/Users/yeomhan-eol/COMSC210/Assignment/movie.txt");
    string title;
    string writer;
    int year;

    if (!inFile.is_open())
    {
        cout << "file is not open!" << endl;
        return 4;
    }

    while (getline(inFile, title))
    {
        inFile >> year;
        inFile.ignore();
        getline(inFile, writer);

        Movie tmp;
        tmp.setTitle(title);
        tmp.setYear(year);
        tmp.setWriter(writer);

        movie.push_back(tmp);
    }
    inFile.close();

    for(Movie m:movie)
    {
        m.print();
    }
    

    return 0;
}