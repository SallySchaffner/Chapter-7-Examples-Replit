// Rainfall Statistics 
// This program gets average monthly rainfall amounts for a year. 
// It writes a report showing the total rainfall for the year, 
// the yearly average rainfall amount,
// the month and amount for the smallest monthly average and the
// month and amount for the largest monthly average. 

#include <iostream>
#include <iomanip>

using namespace std;

const string MONTHS[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int NUM_MONTHS = 12;

// Input - an array reference
// Output - returns the number of items in the array
// Postconditions - the rainfall amounts are all greater than 0. 
int getData(double arrayRef[]);

// Input - an array reference and the number of items in the array
// Output - returns the sum of the items in the array
double sum(double arrayRef[], int numItems);

// Input - an array reference and the number of items in the array
// Output - returns the location (index) of the smallest item in the array
int min(double arrayRef[], int numItems);

// Input - an array reference and the number of items in the array
// Output - returns the location (index) of the largest item in the array
int max(double arrayRef[], int numItems);

// Input - the total rainfall amount for the year, the number of months included,
// the index of the month with the smallest rainfall amount, the index of the month
// with the largest rainfall amount.
// Postcondition - A report showing the rainfall amounts for the year, 
// the monthly average rainfall amount, the month and amount which had the 
// smallest rainfall, the month and amount which has the largest rainfall. 
void writeReport(double arrayRef[], int numItems, double sum, int minIndex, int maxIndex);


int main()
{
    double rainfall[NUM_MONTHS];
    double totalRainfall;
    int minIndex, maxIndex;

    int nItems = getData(rainfall);
    totalRainfall = sum(rainfall, nItems);
    minIndex = min(rainfall, nItems);
    maxIndex = max(rainfall, nItems);
    writeReport(rainfall, nItems, totalRainfall, minIndex, maxIndex);

    return 0;
}

int getData(double arrayRef[])
{
    for (int m = 0; m < NUM_MONTHS; m++)
    {
        cout << "Enter the monthly average rainfall amount (in inches) for " << MONTHS[m] << ": ";
        cin >> arrayRef[m];
        while (arrayRef[m] < 0)
        {
            cout << "Rainfall amount must be > 0, please re-enter" << endl;
            cin >> arrayRef[m];
        }          
    }
    cout << endl;
    return NUM_MONTHS;
}

double sum(double arrayRef[], int numItems)
{
    double total = 0.;
    for (int i = 0; i < numItems; i++)
    {
        total += arrayRef[i];
    }
    return total;
}

int min(double arrayRef[], int numItems)
{
    int low = 0;
    for (int i = 1; i < numItems; i++)
    {
        if (arrayRef[i] < arrayRef[low])
            low = i;
    }
    return low;
}

int max(double arrayRef[], int numItems)
{
    int high = 0;
    for (int i = 1; i < numItems; i++)
        if (arrayRef[i] > arrayRef[high])
            high = i;
    return high;
}

void writeReport(double rainfall[], int numItems, double sum, int minIndex, int maxIndex)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "Rainfall Statistics\n" << "(amounts in inches)" << endl;
    cout << "Total amount of rain for the year: " << sum << endl;
    cout << "Average amount of rain for the year: " << (sum / numItems) << endl;
    cout << MONTHS[minIndex] << " had the smallest rainfall amount: " << rainfall[minIndex] << endl;
    cout << MONTHS[maxIndex] << " had the greatest rainfall amount: " << rainfall[maxIndex] << endl;
}
