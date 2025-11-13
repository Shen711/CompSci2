//Program Name: Stereo Reciever
//Author: Nathan Schoenike
//Date Last Updated: 11/10/2025
//Purpose: To input data about a specific stereo receiver with try-catch blocks
#include <string>
#include <iostream>
#include <limits.h>
#include <limits>


using namespace std;

template <typename T>

class Grade
{
    //array which corresponds to template
    T quizScores[16];

    int highScore;
    int lowScore;
    int quizscore;

    public:
    
    int getModuleScore(int index)
    {
        
        if (imdex < 0 || index > 15)
        {
            throw invalid_argument("Module number must be between 1 and 16. ");
        }
        return quizScores[index];
        
    }
    int getHigh()
    {
        return highScore;
    }

    int getLow()
    {
        return lowScore;
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

}