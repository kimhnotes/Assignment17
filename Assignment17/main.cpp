// Name: Kim Hoang
// Date: 11/8/2023
// Description: Assignment 17

#include <iostream>
#include <fstream>
#include "input.h"
#include <map>

using namespace std;

// Function Prototypes

int menuOption();
void Challenge3();
void Challenge4();
void Challenge6();
void Challenge7();
void Challenge8();

int menuOption()
{
    system("cls");
    cout << "\n\tChapter 17 - Assignments by Kim Hoang";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t3. Challenge 3 - Capital Quiz";
    cout << "\n\t4. Challenge 4 - ";
    cout << "\n\t6. Challenge 6 - ";
    cout << "\n\t7. Challenge 7 - ";
    cout << "\n\t8. Challenge 8 - ";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0. exit";
    cout << "\n\t" << string(60, char(205));

    return inputInteger("\n\tOption: ", 0, 8);
}

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 3: Challenge3(); break;   
        case 4: Challenge4(); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break; // 10 points Extra credit
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}

void Challenge3()
{
    system("cls");
    cout << "\n\t3. Challenge 3 - Capital Quiz";
    cout << "\n\t" << string(60, char(196));

    fstream file;

    file.open("states.txt");

    if (file.fail())
    {
        cout << "\nERROR: Cannot read states.txt.\n";
        return;

    }

    map<string, string> USStates;

    string name;
    string capital;

    while (getline(file, name))
    {
        getline(file, capital);
        USStates.insert(pair<string, string>(name, capital));
    }
    file.close();

    int corrects = 0;
    int incorrects = 0;

    do
    {
        auto it = USStates.begin();
        advance(it, rand() % 50);

        cout << "\nWhat is capital of " << it->first << "? ";
        getline(cin, capital);

        if (capital == it->second)
        {
            cout << "\nCorrect!\n";
            corrects++;
        }
        else
        {
            cout << "\nIncorrect. Please check your spelling.\n";
            incorrects++;

        }

        char ans = toupper(inputChar("\nDo you want to continue (Y-yes or N-no)? "));

        if (ans == 'N')
            break;

    } while (true);

    cout << "\nCorrect answers  : " << corrects << '\n';
    cout << "Incorrect answers: " << incorrects << '\n';
}

void Challenge4()
{
	system("cls");
	cout << "\n\t4. Challenge 4 - ";
	cout << "\n\t" << string(60, char(196));

}

void Challenge6()
{
	system("cls");
	cout << "\n\t6. Challenge 6 - ";
	cout << "\n\t" << string(60, char(196));

}

void Challenge7()
{
	system("cls");
	cout << "\n\t7. Challenge 7 - ";
	cout << "\n\t" << string(60, char(196));

}

void Challenge8()
{
	system("cls");
	cout << "\n\t8. Challenge 8 - ";
	cout << "\n\t" << string(60, char(196));

}
