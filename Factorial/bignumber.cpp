#include "bignumber.h"

BigNumber::~BigNumber()
{
    array.clear();
}

/*
* Creates BigNumber with [number] value
* Example: BigNumber(128) -> *this->[array] = vec[1, 2, 8]
*/
BigNumber::BigNumber(int number)
{
    array.resize(lenght(number));
    setVector(number);
}

/*
* CreatesBigNumber with zero value
*/
BigNumber::BigNumber()
{
    array.resize(1);
    array[0] = 0;
}

/*
* Returns number of digits in [number]
*/
int BigNumber::lenght(int number)
{
    int lenght = 0;
    while(number)
    {
        number /= 10;
        lenght++;
    }

    return lenght;
}

/*
* Fills *this->[array] vector with digits from [number]
*/
void BigNumber::setVector(int number)
{
    setVector(number, this->array);
}

/*
* Fills &[array] vector from second parameter with digits from [number]
*/
void BigNumber::setVector(int number, vector<int> &array)
{
    for(int i = 0, dec = 10, leng = lenght(number); i < leng; i++)
    {
        array[i] = number % dec;
        number /= dec;
    }
}

/*
* Fills &[array] array from second parameter with digits from [number]
*/
void BigNumber::setArray(int number, int *array)
{
    for(int i = 0, dec = 10, leng = lenght(number); i < leng; i++)
    {
        array[i] = number % dec;
        number /= dec;
    }
}

/*
* Multiply *this->[array] vector with number
*/
void BigNumber::multiply(int number)
{
    int Nlengh = lenght(number);

    vector<int>num;
    num.resize(Nlengh);
    setVector(number, num);
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

/*
* Shifts every element in vector bigger than 10 in order to represent each digits of number
* Example: fixVector([5, 12, 2]) -> [6, 2, 2]
*/
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

/*
* Prints to console digits stored in *this->[array]
*/
void BigNumber::writeNumber()
{
    for(int i = (array.size() - 1); i >= 0; i--)
    {
        cout << array[i];
    }
    cout << endl;
}
