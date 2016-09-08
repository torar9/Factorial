#include <iostream>
#include "bignumber.h"

using namespace std;

int main()
{
    cout << "Enter factorial" << endl;
    int number;
    cin >> number;

    //cout << 9999  10 << endl;
    BigNumber *bign = new BigNumber(number);

    while(number > 1)
    {
        number--;
        bign->multiply(number);
    }
    bign->writeNumber();

    delete bign;
    return 0;
}
