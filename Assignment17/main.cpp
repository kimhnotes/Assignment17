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
    cout << "\n\t4. Challenge 4 - File Encryption and Decryption";
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
    cout << "\n\t4. Challenge 4 - File Encryption and Decryption";
    cout << "\n\t" << string(60, char(196));

    map<char, char> codes = {
        {'A', '%'}, {'a', '9'},
        {'B', '@'}, {'b', '#'},
        {'C', '!'}, {'c', '$'},
        {'D', '^'}, {'d', '&'},
        {'E', '*'}, {'e', '('},
        {'F', ')'}, {'f', '_'},
        {'G', '+'}, {'g', '-'},
        {'H', '='}, {'h', '{'},
        {'I', '}'}, {'i', '['},
        {'J', ']'}, {'j', '|'},
        {'K', '\\'}, {'k', ';'},
        {'L', ':'}, {'l', '"'},
        {'M', '<'}, {'m', ','},
        {'N', '>'}, {'n', '.'},
        {'O', '?'}, {'o', '/'},
        {'P', '1'}, {'p', '2'},
        {'Q', '3'}, {'q', '4'},
        {'R', '5'}, {'r', '6'},
        {'S', '7'}, {'s', '8'},
        {'T', '0'}, {'t', 'a'},
        {'U', 'b'}, {'u', 'c'},
        {'V', 'd'}, {'v', 'e'},
        {'W', 'f'}, {'w', 'g'},
        {'X', 'h'}, {'x', 'i'},
        {'Y', 'j'}, {'y', 'k'},
        {'Z', 'l'}, {'z', 'm'}
    };

    // Get the input file name
    string fileName = inputString("\n\tEnter the name of the file to encrypt/decrypt: ", true);

    fstream file;
    file.open(fileName, ios::in);

    if (file.fail())
    {
        cout << "\n\tERROR: Cannot read " << fileName << ".\n";
        return;
    }

    char choice = inputChar("\n\tDo you want to (E)ncrypt or (D)ecrypt? ");
    string resultFileName;

    if (choice == 'E' || choice == 'e')
    {
        resultFileName = inputString("\n\tEnter the name of the file to write encrypted data: ", true);
    }
    else if (choice == 'D' || choice == 'd')
    {
        resultFileName = inputString("\n\tEnter the name of the file to write decrypted data: ", true);
    }
    else
    {
        cout << "\n\tInvalid choice. Exiting.\n";
        return;
    }

    char key;
    file.close();

    file.open(fileName, ios::in);

    if (file.fail())
    {
        cout << "\n\tERROR: Cannot read " << fileName << ".\n";
        return;
    }

    string result = "";

    while (file >> ws >> key)
    {
        if (codes.find(key) != codes.end())
        {
            if (choice == 'E' || choice == 'e')
            {
                result += codes[key];
            }
            else if (choice == 'D' || choice == 'd')
            {
                for (const auto& pair : codes)
                {
                    if (pair.second == key)
                    {
                        result += pair.first;
                        break;
                    }
                }
            }
        }
        else
        {
            result += key;
        }
    }

    file.close();

    file.open(resultFileName, ios::out);

    if (file.fail())
    {
        cout << "\n\tERROR: Cannot write " << resultFileName << ".\n";
        return;
    }

    file << result;

    file.close();

    cout << "\n\tFile encryption or decryption completed.\n";
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
