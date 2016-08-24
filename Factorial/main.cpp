#include <iostream>
#include "bignumber.h"

using namespace std;

int main()
{
    cout << "Enter factorial" << endl;
    int number;
    cin >> number;

    BigNumber *bign = new BigNumber(number);
    number--;
    while(number >= 2)
    {
        bign->multiply(number);
        number--;
    }
    bign->writeNumber();

    delete bign;
    return 0;
}
