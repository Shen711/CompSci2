//Program Name: Non-Duplicate Words
//Author: Nathan Schoenike
//Date Last Updated: 11/17/2025
//Purpose: To read in a file and display the words in the file in ascending order

#include <fstream> //for file
#include <set> //for assignment
#include <limits>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    //the set will automatically take in only unique values,  
    set<string> nonduplicate;
    string word;

    fstream wordFile("M3P2A.txt");

    if (!wordFile)
    {
        cout << "Could not open file. Try again" << endl;
        return 0;
    }

    else 
    {
        while (wordFile >> word)
        {
            nonduplicate.insert(word);
        }
    }

    cout << "Unique words in the file: " << endl;
    int Siz = nonduplicate.size();

    cout << Siz << endl;

    //Words automatically sort in ascending order of letter in word
    cout << "Words in ascending order: " << endl;
    for (auto word : nonduplicate)
    {
        cout << word << endl;
    }

    wordFile.close();

    return 0;


    


}