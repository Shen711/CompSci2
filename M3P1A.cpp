//Program Name: Quiz Grades
//Author: Nathan Schoenike
//Date Last Updated: 11/10/2025
//Purpose: To input quiz grades and display average and high and low scores 
#include <string>
#include <iostream>
#include <limits.h>
#include <limits>
#include <iomanip>


using namespace std;

template <typename T>

class Grade
{
    //array which corresponds to template
    T quizScores[16];

    int moduleNum;
    int lowmoduleNum;
    int lowScore;
    int quizscore;

    public:
    
    int getModuleScore(int score)
    {
        
        
        return quizScores[score];
        
        
    }
    int getHigh()
    {
        int highvalue = 0;
        int moduleNum;
        for (int i = 0; i < 16; i++)
        {
            //loop that compares every value to the last, if it isnt higher it skips. 
            if (quizScores[i] > highvalue)
            {
                highvalue = quizScores[i];
                moduleNum = i + 1;
            }
        }
        return moduleNum;
    }

    int getLow()
    {
        int lowvalue = 101;
        lowmoduleNum = 0;
        for (int i = 0; i < 16; i++)    
        {
            if (quizScores[i] < lowvalue)
            {
                lowvalue = quizScores[i];
                //finds the module number based on comparing the elements
                lowmoduleNum = i + 1;
            }



        }
        
        return lowmoduleNum;
    }   

    double getAverage()
    {
        //initialize sum because average is 0 right now
        int sum = 0;
        for (int i = 0; i < 16; i++)
        {
            sum += quizScores[i];
        }
        //average varable to divide the sum, to make it a double put it through static cast
        double average = static_cast<double>(sum) / 16.0;

        return average;
    }
    //all values returned are of type T, but the assignment only calls for integers. Figured I would keep it as template to demonstrate I know the difference
    // T getData()
    // {
    //     cout << "Grade Calculator" << endl;
    //     cout << "----------------" << endl;
    //     cout << "Please enter " << num << " quiz scores: " << endl;
        
    // }

    void getData()
    {
        int quizscore;

        cout << "Grade Calculator" << endl;
        cout << "----------------" << endl;
        cout << "Please enter 16 quiz scores by order of module starting from 1: " << endl;

        for (int i = 0; i < 16; i++)
        {
            cin >> quizscore;
            if (!cin || quizscore < 0 || quizscore > 100)
            {
                throw invalid_argument("Quiz score must be an integer between 0 and 100. ");
            }
            quizScores[i] = quizscore;
        }

    }
};

int main()
{

    Grade<int> QuizGrades;

    try
    {
        QuizGrades.getData();
    }
    catch (invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
        cout << "Please try again. " << endl;
        return 1;
    }

    for (int i = 0; i < 16; i++)
    {
        cout << "Module " << i + 1 << ": " << QuizGrades.getModuleScore(i) << endl;

    }
    
    //gets high and low corresponding index, then it is plugged into the 
    int highScoreModule = QuizGrades.getHigh();
    int lowScoreModule = QuizGrades.getLow();

    int highScore = QuizGrades.getModuleScore(highScoreModule - 1);
    int lowScore = QuizGrades.getModuleScore(lowScoreModule - 1);


    //display high and low scores
    cout << "Your high Score was in Module " << highScoreModule << ": " << highScore  << endl;
    cout << "Your low Score was in Module " << lowScoreModule << ": " << lowScore <<  endl;

    cout << "Average Score is  " << fixed << setprecision(2) << QuizGrades.getAverage() << endl;



}