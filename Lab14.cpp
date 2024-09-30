#include <iostream>

using namespace std;

class Color
{
    private:
        int red;
        int green;
        int blue;
        string name;
    
    public:
        // setter & getter
        string getName() {return name;}
        void setName(string n) { name = n; } 
        int getRed() const {return red;}
        void setRed(int r) {red = r;}
        int getGreen() const {return green;}
        void setGreen(int g) { green = g;}
        int getBlue() const {return blue;}
        void setBlue(int b) { blue = b;}

        void print() const
        {
            cout << "COLOR : " << name << endl;
            cout << "RED : " << red << endl;
            cout << "Green : " << green << endl;
            cout << "Blue : " << blue << endl;
        }

};

void print(Color);

int main()
{
    Color yellow;
    yellow.setName("Yellow");
    yellow.setRed(255);
    yellow.setGreen(255);
    yellow.setBlue(0);
    yellow.print();
    print(yellow);

    Color orange;
    orange.setName("orange");
    orange.setRed(255);
    orange.setGreen(125);
    orange.setBlue(0);
    orange.print();
    print(orange);

    Color ocean;
    ocean.setName("ocean");
    ocean.setRed(0);
    ocean.setGreen(125);
    ocean.setBlue(255);
    ocean.print();
    print(ocean);




    return 0;
}

void print(Color c)
{
    cout << c.getName() << " (" << c.getRed() << ", " 
         << c.getGreen() << ", " << c.getBlue() <<" )" << endl << endl;
}