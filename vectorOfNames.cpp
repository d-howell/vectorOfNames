//Dalton Howell
//IN200: Intro to C++
//Vector of Names

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    vector<string> names;
    vector<string>::iterator changeIter;
    vector<string>::const_iterator readIter;

    names.push_back("Dalton");
    names.push_back("Brian");
    names.push_back("Johnny");

    string input;

    do
    {
        cout << "Hey there, I've got a list of names for you:\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        for(readIter = names.begin(); readIter != names.end(); ++readIter)
        {
            cout << *readIter << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        do{

        cout << "You may choose to Add, Change, Remove, or Show names!\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Either enter your choice, or enter 'quit' to exit!\n>> ";

        getline(cin,input);
        for(int i = 0; i < input.size();++i) //Changes the string to all uppercase
        {
            input[i] = toupper(input[i]);
        }

        if (input == "ADD")
        {   
            cout << "You'd like to add a name? We can do that!\n";
            cout << "What name would you like to add?\n>>";
            getline(cin,input); //reusing input variable.
            names.push_back(input);
            break;
        } else if (input == "CHANGE") {
            break;
        } else if (input == "REMOVE") {
            break;
        } else if (input == "SHOW") {
            break;
        } else if (input == "QUIT") {
            break;
        } else {
            cout << "\nInvalid input! Try again.\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
            continue;
        }
        }while(true);

    }while(input != "QUIT");
}