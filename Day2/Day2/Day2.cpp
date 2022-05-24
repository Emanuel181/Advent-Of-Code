#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void GetInstruction(const char Str[], char Instruction[])
{
    unsigned long long position = strchr(Str, ' ') - Str;
    char word[256];
    unsigned long long index = 0;
    for (unsigned long long i = 0; i < position; ++i) word[index++] = Str[i];
    word[index] = '\0';

    strcpy(Instruction, word);
}


void GetNumber(const char Str[], unsigned long long& Number)
{
    Number = 0;
    unsigned long long position = strchr(Str, ' ') - Str;
    unsigned long long power = 1;

    for (unsigned long long i = position + 1; Str[i]; ++i)
    {
        Number = Number * power + (Str[i] - '0');
        power *= 10;
    }
}


ifstream fin("Text.txt");


int main()
{

    char str[256];
    unsigned long long depth = 0, horizontalPosition = 0;

    while (fin.getline(str, 255))
    {
        // Get instruction (forward, up or down)
        char instruction[256]; GetInstruction(str, instruction);

        // Get number
        unsigned long long number; GetNumber(str, number);


        if (strcmp(instruction, "forward") == 0) horizontalPosition += number;
        else if (strcmp(instruction, "up")) depth += number;
        else depth -= number;
    }

    cout << horizontalPosition * depth;

    fin.close();

    return 0;
}