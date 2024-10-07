#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// movies
// The Godfather
// Fast & The Furious
// Tenet
// The Avengers

// defined struct
struct Node
{
    double rating;  // rating(1.0 ~ 5.0)
    string comment; // comment
    Node *next;     // ptr to next Node
};

class Movie
{
private:
    string title; // movie title
    Node *head;   // head ptr

public:
    Movie(string s)
    {
        title = s;
        head = nullptr;
    }

    void addHead(double r, const string& c)
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

    void outputting() const
    {
        if (!head)
        {
            cout << "Empty list.\n";
            return;
        }
        int count = 1;
        double total = 0;
        Node *current = head;

        cout<< "----"<< title <<"----" << endl;
        while (current)
        {
            cout << setw(5) << "" << "> Review #" << fixed << setprecision(1)
            << count++ << ": " << current->rating << ": " << current->comment << endl;
            total += current->rating;
            current = current->next;
        }
    
        cout << setw(5) << "" << "> Average: " << total / (count - 1) << endl;
    }

    double randomRating()
    {
        double randomRating = (static_cast<double>(rand()) / RAND_MAX * 4.0) + 1.0;
        return randomRating;

    }

    void fileComment(ifstream& f, int j, const string& file)
    {
        string comment;
        for(int i = 0; i< j; i++){

            if(!getline(f, comment)){
                f.clear();
                f.close();
                f.open(file);
                getline(f, comment);
            }
            double rate = randomRating();
            this->addHead(rate, comment);
        }
    }
};

int main()
{
    // container vector
    vector<Movie> movies;
    movies.push_back(Movie("The Godfather"));
    movies.push_back(Movie("Fast & The Furious"));
    movies.push_back(Movie("Tenet"));
    movies.push_back(Movie("The Avengers"));
    
    string fileName = "/Users/yeomhan-eol/COMSC210/Assignment/movie19.txt";
    ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        cout << "file is not opened!!" << endl;
        return 4;
    }
    srand (static_cast<double>(time(0)));


    for(Movie& movie : movies){
        movie.fileComment(inFile, 3, fileName);
    }

    for(const Movie& movie : movies){
        movie.outputting();
        cout << endl;
    }



    inFile.close();
    return 0;
}