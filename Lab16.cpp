// COMSC-210 | Lab 16 | Haneol Yeom
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
        //default constructor
        Color()
        {
            name = "yellow";
            red = 255;
            green = 255;
            blue = 0;
        }

        //parameter constructor
        Color(string n, int r, int g, int b)
        {
            name = n;
            red = r;
            green = g;
            blue = b;
        }

        //partial constructor
        Color(string n)
        {
            name = n;
            red = 0;
            green = 125;
            blue = 255;
        }


        void print() const
        {
            cout << "COLOR : " << name << endl;
            cout << "RED : " << red << endl;
            cout << "Green : " << green << endl;
            cout << "Blue : " << blue << endl;
        }

};


int main()
{

    Color yellow;
    yellow.print();

    Color orange("orange", 255, 125, 0);
    orange.print();

    Color ocean("ocean");
    ocean.print();




    return 0;
}