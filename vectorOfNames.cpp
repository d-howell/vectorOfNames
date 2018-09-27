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
    names.push_back("Len");

    string input;

    do
    {
        cout << "I've got a list of names for you:\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        for(readIter = names.begin(); readIter != names.end(); ++readIter) //list all names
        {
            cout << *readIter << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }

        do{ //Do loop to repeat the choice selection when given an invalid input

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
                cout << "What name would you like to add?\n>> ";
                getline(cin,input); //reusing input variable.
                names.push_back(input);
                break;

            } else if (input == "CHANGE") {

                do{ //Do loop in case they enter a name not on the list
                    cout << "Which name would you like to change? This is case-sensitive!\n>> ";
                    getline(cin, input);
                    changeIter = find(names.begin(),names.end(),input);

                    if(changeIter != names.end())
                    {
                        cout << "\nFound it! Now, what would you like to change it to?\n>> ";
                        getline(cin,input);
                        (*changeIter) = input;
                        break;

                    } else {

                        cout << "Name not found! Try again.";
                    }
                }while(true);
                break;
            } else if (input == "REMOVE") { //remove names
                
                do{
                    cout << "Which name would you like to remove? This is case-sensitive!\n>> "; //warn player name is case sensitive
                    getline(cin,input);
                    readIter = find(names.begin(),names.end(), input); //find the input
                    if(readIter != names.end())
                    {   
                        names.erase(readIter);
                    } else {
                        cout << "I can't seem to find that name, try again.\n";
                        continue; //Sends to top of loop, ignoring all code below
                    }
                    cout << endl << input << " has been removed!\n";
                    break;
                    this_thread::sleep_for(chrono::milliseconds(1000));
                }while(true);
                break;

            } else if (input == "SHOW") { //Since the names are listed at the beginning, to list again, break the do loop
                sort(names.begin(),names.end()); //sort names
                break;

            } else if (input == "QUIT") { //quit the program

                break;

            } else {

                cout << "\nInvalid input! Try again.\n";
                this_thread::sleep_for(chrono::milliseconds(1000));
                continue;
            }
        }while(true);//do loop here to return when an invalid input is given

    }while(input != "QUIT"); //quit program

    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Thank you!";
    this_thread::sleep_for(chrono::milliseconds(1000));

}