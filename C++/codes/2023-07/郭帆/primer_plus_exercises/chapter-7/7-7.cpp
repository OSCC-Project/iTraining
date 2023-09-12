// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
double* fill_array(double ar[], int limit);
void show_array(const double ar[], double* end);  // don't change data
void revalue(double r, double ar[], double* end);
 
int main()
{
    using namespace std;
    double properties[Max];
 
    double* end = fill_array(properties, Max);
    show_array(properties, end);
    if (end > properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
 
double* fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    double *p = ar;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        *p = temp;
        p++;
    }
    return p;
}
 
// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], double* end)
{
    using namespace std;
    const double *p = ar;
    for (int i = 0; p != end; i++, p++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << *p << endl;
    }
}
 
// multiplies each element of ar[] by r
void revalue(double r, double ar[], double* end)
{
    for (double *p = ar; p != end; p++)
        *p *= r;
}
