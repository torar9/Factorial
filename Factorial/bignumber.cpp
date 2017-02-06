#include "bignumber.h"

BigNumber::~BigNumber()
{
    array.clear();
}

BigNumber::BigNumber(int number)
{
    array.resize(lenght(number));
    setVector(number);
}

BigNumber::BigNumber()
{
    array.resize(1);
    array[0] = 0;
}

int BigNumber::lenght(int number)//počet číslic v čísle
{ 
    int lenght = 0;
    while(number)
    {
        number /= 10;
        lenght++;
    }

    return lenght;
}

void BigNumber::setVector(int number)
{
    setVector(number, this->array);
}

void BigNumber::setVector(int number, vector<int> &array)
{
    for(int i = 0, dec = 10, leng = lenght(number); i < leng; i++)
    {
        array[i] = number % dec;
        number /= dec;
    }
}

void BigNumber::setArray(int number, int *array)
{
    for(int i = 0, dec = 10, leng = lenght(number); i < leng; i++)
    {
        array[i] = number % dec;
        number /= dec;
    }
}

void BigNumber::multiply(int number)
{
    int Nlengh = lenght(number);

    int num[Nlengh];
    setArray(number, num);
    vector<int> arrHelp(array.size() + (Nlengh - 1));

    for(string::size_type i = 0; i < Nlengh; i++)
    {
        for(string::size_type j = 0; j < array.size(); j++)
        {
            arrHelp[i + j] += (num[i] * array[j]);
        }
    }

    fixVector(arrHelp);
    array = arrHelp;
}

void BigNumber::fixVector(vector<int> &array)
{
    string::size_type i = 0, carry = 0;
    while(!(carry == 0 && i >= array.size()))
    {
        if(i == array.size())
            array.push_back(carry);
        else
            array[i] += carry;

        carry = array[i] / 10;
        array[i] -= carry * 10;
        i++;
    }
}

void BigNumber::writeNumber()
{
    for(int i = (array.size() - 1); i >= 0; i--)
    {
        cout << array[i];
    }
    cout << endl;
}
