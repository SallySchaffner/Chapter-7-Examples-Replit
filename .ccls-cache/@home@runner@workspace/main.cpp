// Driver's License Exam - This program grades a driver's license exam and 
// determines whether or not the applicant passed the exam. 

#include <iostream>

const int NUM_QUESTIONS = 20;
const int NUM_TO_PASS = 15;

using namespace std;

// This function gets the answers to an exam from interactive input.
// The answers are restricted to the letters 'A', 'B', 'C', or 'D'
void getData(char examAnswers[], int numItems);


// This function compares the correct answers to an applicant's answers and keeps track of the incorrect answer
// Input -array containing the correct answers
//        array containing the applicant's answer
//        the number of questions in the array
// Output - returns the number of incorrect answers
// Postcondition - A list of the numbers of incorrectly answered questions is produced. 

int gradeExam(char correct[], char applicant[], int numItems, int incorrect[]);

// This function writes a report showing the number of correct anwers, the number of incorrect answer, and a list of the questions missed. 
// It also write a message indicating whether the applicant passed or failed the exam.
// Input - number of questions on the exam.
//       - number of correct answers to pass
//       - number of questions answered incorrectly
//       - vector of incorrectly answered question numbers
void writeReport(int numberQuestions, int numberToPass, int numberIncorrect, int incorrect[]);


int main()
{

    char correctAnswers[] = { 'A', 'D', 'B', 'B', 'C', 
                              'B', 'A', 'B', 'C', 'D', 
                              'A', 'C', 'D', 'B', 'D', 
                              'C', 'C', 'A', 'D', 'B' };
    char answers[NUM_QUESTIONS];
    int incorrectQuestions[NUM_QUESTIONS];
    int incorrectAnswers;

    getData(answers, NUM_QUESTIONS);
    incorrectAnswers = gradeExam(correctAnswers, answers, NUM_QUESTIONS, incorrectQuestions);
    writeReport(NUM_QUESTIONS, NUM_TO_PASS, incorrectAnswers, incorrectQuestions);

    return 0;
}

void getData(char examAnswers[], int numItems)
{
    for (int i = 0; i < numItems; i++)
    {
        cout << "Answer for Question " << (i + 1) << ": ";
        cin >> examAnswers[i];
        while (examAnswers[i] < 'A' || examAnswers[i] > 'D')
        {
            cout << "Enter A, B, C, or D: ";
            cin >> examAnswers[i];
        }
    }
    cout << endl;
}

int gradeExam(char correct[], char applicant[], int numItems, int incorrect[])
{
    int wrongAnswers = 0;
    for (int i = 0; i < numItems; i++)
    {
        if (correct[i] != applicant[i]) 
        {
            incorrect[wrongAnswers++] = i;
        }
    }
    return wrongAnswers;
}

void writeReport(int numberQuestions, int numberToPass, int numberIncorrect, int incorrect[])
{
    cout << "Results of your Driver's License exam: " << endl;
    int numberCorrect = numberQuestions - numberIncorrect; 
    cout << "Questions answered: " << numberCorrect << endl;
    cout << "Questions missed: " << numberIncorrect << endl;
    if (numberIncorrect > 0)
    {
        cout << "Questions you missed: " << endl;
        for (int i = 0; i < numberIncorrect; i++)
            cout << incorrect[i] << " ";
        cout << endl;
    }
    if (numberCorrect < numberToPass)
        cout << "You did not pass the exam." << endl;
    else
        cout << "You passed the exam." << endl;
}

