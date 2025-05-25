// Rain or Shine
// This analyzes the number of sunny, rainy, and cloudy days over a 3 month period
// and writes a report. 

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_MONTHS = 3;
const int NUM_DAYS = 30;
const int NUM_CLASSES = 3;
const int RAIN_COL = 1;
const string MONTHS[] = { "June", "July", "August" };
const string fileName = "RainOrShine.txt";

// This function takes as input an input file object, and an array reference to a
// 2-dimensional array with 30 columns, and an integer specifying the number of rows
// Preconditions – the file has already been open and validated for reading.
// Postcondition – the data has been transferred from the file into the array.
void getData(ifstream & inFile, char weather[][NUM_DAYS], int rows);

// This function takes as input a reference to the weather array and to a 3 x 3 array 
// which will contain the count of sunny, rainy, and cloudy days for each month. 
// Preconditions – the weather array contains the data for each day of the month.
// Postcondition – the second array contains the count of sunny, rainy, and cloudy days for each month.
void classifyWeather(char weather[][NUM_DAYS], int rows, int weatherSummary[][NUM_CLASSES]);

// This function takes as input an array reference, the number of rows in the array, and a column index.
// It returns the row index of the column with the maximum value for that column.
int columnMax(int weatherSummary[][NUM_CLASSES], int rows, int col);

//This function takes as input an array reference to the summary weather array, the number of rows in the array, 
// and the row index of where the maximum rainy day count occurs.
// Precondition - the row number with the maximum number of rainy days has already been determined
// Postcondition – A report is created showing the number of sunny, rainy, and cloudy days for each month 
// and then displays the name of the month with the most rainy days.
void writeReport(int weatherSummary[][NUM_CLASSES], int rows, int maxRow);

int main()
{
    char weather[NUM_MONTHS][NUM_DAYS];
    int weatherSummary[NUM_MONTHS][NUM_CLASSES];
    int maxRow;

    ifstream inFile(fileName);
    if (inFile.fail())
    {
        cout << "Could not open " << fileName;
        return 1;
    }

    getData(inFile, weather, NUM_MONTHS);
    classifyWeather(weather, NUM_MONTHS, weatherSummary);
    maxRow = columnMax(weatherSummary, NUM_MONTHS, RAIN_COL);
    writeReport(weatherSummary, NUM_MONTHS, maxRow);
    return 0;
}

void getData(ifstream& inFile, char weather[][NUM_DAYS], int rows)
{
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < NUM_DAYS; c++)
            inFile >> weather[r][c];
}

void classifyWeather(char weather[][NUM_DAYS], int rows, int weatherSummary[][NUM_CLASSES])
{
    int sunny, rainy, cloudy;

    for (int r = 0; r < rows; r++)
    {
        sunny = 0;
        rainy = 0;
        cloudy = 0;
        for (int c = 0; c < NUM_DAYS; c++)
        {
            if (weather[r][c] == 'S')
                sunny++;
            else if (weather[r][c] == 'R')
                rainy++;
            else
                cloudy++;
        }
        weatherSummary[r][0] = sunny;
        weatherSummary[r][1] = rainy;
        weatherSummary[r][2] = cloudy;
    }
}

int columnMax(int weatherSummary[][NUM_CLASSES], int rows, int col)
{
    int maxRainy = 0;
    for (int r = 1; r < rows; r++)
    {
        if (weatherSummary[r][col] > weatherSummary[maxRainy][col])
            maxRainy = r;
    }

    return maxRainy;
}

void writeReport(int weatherSummary[][NUM_CLASSES], int rows, int maxRow)
{
    cout << "Summer Weather" << endl;
    cout << "Month" << "     " << "Sunny" << "     " << "Rainy" << "     " << "Cloudy" << endl;
    for (int r = 0; r < rows; r++)
        cout << setw(6) << left << MONTHS[r] << setw(8) << right << weatherSummary[r][0] << setw(10) << weatherSummary[r][1] << setw(10) << weatherSummary[r][2] << endl;
    cout << "The month with the most number of rainy days was: " << MONTHS[maxRow] << endl;
}

