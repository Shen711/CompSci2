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

    for (int i = 0; i < Siz; i++)
    {
        cout << i << endl;
    }


}