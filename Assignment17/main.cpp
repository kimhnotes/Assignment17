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

    map<char, char> encrypt = {
        {'A', '%'}, {'B', '@'}, {'C', '#'}, {'D', '$'},
        {'E', '^'}, {'F', '&'}, {'G', '*'}, {'H', '('},
        {'I', ')'}, {'J', '!'}, {'K', '+'}, {'L', '='},
        {'M', '|'}, {'N', '['}, {'O', ']'}, {'P', '{'},
        {'Q', '}'}, {'R', ':'}, {'S', ';'}, {'T', '"'},
        {'U', '\''}, {'V', '?'}, {'W', ','}, {'X', '.'},
        {'Y', '<'}, {'Z', '>'},
        {'a', '9'}, {'b', '#'}, {'c', '*'}, {'d', '!'},
        {'e', '('}, {'f', ')'}, {'g', '+'}, {'h', '='},
        {'i', '|'}, {'j', '['}, {'k', ']'}, {'l', '{'},
        {'m', '}'}, {'n', ':'}, {'o', ';'}, {'p', '"'},
        {'q', '\''}, {'r', '?'}, {'s', ','}, {'t', '.'},
        {'u', '<'}, {'v', '>'}
    };

    map<char, char> decrypt;

    for (const auto& pair : encrypt)
    {
        decrypt[pair.second] = pair.first;
    }

    char key;

    char choice = inputChar("\n\tChoose operation (E - Encrypt, D - Decrypt): ", "EDed");

    string fileName;
    string outputFileName;

    if (toupper(choice) == 'E')
    {
        fileName = inputString("\n\tEnter the name of the file to encrypt (example file is called \"testOriginal.txt\"): ", true);
        outputFileName = inputString("\n\tEnter the name of the file to write encrypted data (example file is called \"blankForEncryption.txt\"): ", true);
    }
    else if (toupper(choice) == 'D')
    {
        fileName = inputString("\n\tEnter the name of the file to decrypt (example file is called \"test_encrypted.txt\"): ", true);
        outputFileName = inputString("\n\tEnter the name of the file to write decrypted data (example file is called \"blankForDecryption.txt\"): ", true);
    }

    fstream file(fileName, ios::in);

    if (file.fail())
    {
        cout << "\n\tERROR: Cannot read " << fileName << ".\n";
        return;
    }

    string result = "";

    while (file >> key)
    {
        if (toupper(choice) == 'E')
        {
            auto it = encrypt.find(key);
            if (it != encrypt.end())
            {
                result += it->second;
            }
            else
            {
                result += key;
            }
        }
        else if (toupper(choice) == 'D')
        {
            auto it = decrypt.find(key);
            if (it != decrypt.end())
            {
                result += it->second;
            }
            else
            {
                result += key;
            }
        }
    }

    file.close();

    file.open(outputFileName, ios::out);

    if (file.fail())
    {
        cout << "\n\tERROR: Cannot write " << outputFileName << ".\n";
        return;
    }

    file << result;

    file.close();

    cout << "\n\tFile encryption and decryption completed.\n";
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
