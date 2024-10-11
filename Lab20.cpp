#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {   //default constructor --> we want it to randomly select 3 or 4 legs, 
                // and to randomly select prices (including dollars and cents) from $100.00 to $999.99.
        const int MIN = 10000, MAX = 99999;
        prices = new double[SIZE];
        legs = rand() % 2 + 3;
        for (int i = 0; i < SIZE; i++)
            prices[i]= (rand() % (MAX-MIN+1) + MIN) / (double) 100;
    }

    Chair(int l, double p[SIZE]) {  // parameter constructor -->  Make it have two parameters: number of legs, 
                    // and an array of 3 doubles (the prices).
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    ~Chair()
    {
        delete[] prices;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    cout << "-- creating pointer to first chair object --" << endl;
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with constructor
    cout << "-- creating dynamic chair object with constructor --" << endl;
    double price[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, price);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    // In the third code block (starting at line 67), amend this such that the 
    // default constructors are used to populate these objects.
    cout << "--creating dynamic array of chair objects--" << endl;
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}