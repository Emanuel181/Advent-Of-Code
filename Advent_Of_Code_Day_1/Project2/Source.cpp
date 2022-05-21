#include <iostream>
#include <fstream>


std::ifstream fin("Text.txt");


int main()
{
    unsigned long long pivotDepth, measuredDepth, counter = 0;
    fin >> pivotDepth;

    while (fin >> measuredDepth)
    {
        if (measuredDepth > pivotDepth) ++counter;
        pivotDepth = measuredDepth;
    }

    std::cout << counter;

    return 0;
}