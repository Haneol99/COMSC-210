#include <iostream>
#include <array>

using namespace std;

class Color
{
    private:
        int red;
        int green;
        int blue;
    
    public:
        // setter & getter
        int getRed() const {return red;}
        void setRed(int r) {red = r;}
        int getGreen() const {return green;}
        void setGreen(int g) { green = g;}
        int getBlue() const {return blue;}
        void setBlue(int b) { blue = b;}

        void print() const
        {
            cout << "RED : " << red << endl;
            cout << "Green : " << green << endl;
            cout << "Blue : " << blue << endl;
        }



};

int main()
{

    Color yellow;
    yellow.setRed(255);
    yellow.setGreen(255);
    yellow.setBlue(0);




    return 0;
}