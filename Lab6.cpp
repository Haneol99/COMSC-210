/*Data entry for the array:
    > Element #0: 5.5
    > Element #1: 2.6
    > Element #2: 3.4
    > Element #3: 8.4
    > Element #4: 9.2
Data entry complete.
Outputting array elements: 5.5 2.6 3.4 8.4 9.2 
Sum of values: 29.1
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getElement(double *, int);
void printAll(double *, int);
double sumAll(double *, int);


int main()
{
    int SIZE = 5;
    double *iptr = nullptr;
    iptr = new double[SIZE];


    cout << "Data entry for the array: " << endl;
    getElement(iptr, SIZE);
    cout << "Data entry complete." << endl;

    cout << "Outputting array elements: ";
    printAll(iptr, SIZE);

    double sum = sumAll(iptr, SIZE);
    cout << "Sum of values: " << sum << endl;
    

    delete[] iptr;

    return 0;
}

void getElement(double *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(13) << "> Element #" << i << " : ";
        cin >> a[i];
    }  
}

void printAll(double *a, int size)
{
    for(int i = 0; i< size; i++){
        cout << a[i] << " ";
    } cout << endl;
}

double sumAll(double *a, int size)
{
    double sum = 0;
    for(int i = 0; i< size; i++){
        sum += a[i];
    }
    return sum;
}