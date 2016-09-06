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
    for(int i = 0, dec = 10, leng = lenght(number); i <= leng; i++)
    {
        array[i] = number % dec;
        number /= dec;
        dec *=10;
    }
}

void BigNumber::multiply(int number)
{
    string::size_type i = 0, carry = 0;
    while(!(carry == 0 && i >= array.size()))
    {
        if(i == array.size())
            array.push_back(carry);
        else
            array[i] = ((number * array[i]) + carry);

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
