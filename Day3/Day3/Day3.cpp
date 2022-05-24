#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


ifstream fin("Text.txt");


unsigned long long* InitArr(string binarySeq) { return new unsigned long long[binarySeq.size()]{0}; }


// Fill vector with the digit with the biggest occurence
void FillArr1(vector <bool> &mostCommonDigit, const unsigned long long *arrCountOne, const unsigned long long *arrCountZero, const unsigned long long n)
{
    for (unsigned long long i = 0; i < n; ++i)
    {
        if (arrCountOne[i] > arrCountZero[i]) mostCommonDigit.push_back(1);

        else mostCommonDigit.push_back(0);
    }
}


// Fill vector with the digit with the lowest occurence
void FillArr2(vector <bool>& MostCommonDigit, const unsigned long long* ArrCountOne, const unsigned long long* ArrCountZero, const unsigned long long n)
{
    for (unsigned long long i = 0; i < n; ++i)
    {
        if (ArrCountOne[i] < ArrCountZero[i]) MostCommonDigit.push_back(1);

        else MostCommonDigit.push_back(0);
    }
}


// from base 2 to base 10
unsigned long long GetNumber(vector <bool> Arr)
{
    unsigned long long gamma = 0;
    unsigned int power = 1;

    for (int i = Arr.size() - 1; i > -1; --i)
    {
        gamma += Arr[i] * power << ' ';
        power *= 2;
    }

    return gamma;
}


// 2 arrays where ArrCountOne[i] and ArrCountZero[i] will be the total occurences for every position i
void InitArrays(unsigned long long *ArrCountOne, unsigned long long *ArrCountZero)
{
    string binarySeq;

    while (fin >> binarySeq)
    {
        for (unsigned long long i = 0; i < binarySeq.size(); ++i)
        {
            if ((binarySeq[i] - '0') == 0) ++ArrCountZero[i];
            else ++ArrCountOne[i];
        }
    }
}


int main()
{
    string binarySeq; fin >> binarySeq;

    unsigned long long* arrCountZero = InitArr(binarySeq), *arrCountOne = InitArr(binarySeq);

    for (unsigned long long i = 0; i < binarySeq.size(); ++i)
    {
        if ((binarySeq[i] - '0') == 0) ++arrCountZero[i];
        else ++arrCountOne[i];
    }


    InitArrays(arrCountOne, arrCountZero);

    unsigned long long gamma = 0;
    vector <bool> mostCommonDigit;
    FillArr1(mostCommonDigit, arrCountOne, arrCountZero, binarySeq.size());
    gamma = GetNumber(mostCommonDigit);
    

    unsigned long long epsilon = 0;
    vector <bool> mostLessDigit;
    FillArr2(mostLessDigit, arrCountOne, arrCountZero, binarySeq.size());
    epsilon = GetNumber(mostLessDigit);

    cout << gamma * epsilon;

    return 0;
}