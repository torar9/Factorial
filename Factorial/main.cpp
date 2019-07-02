#include <iostream>
#include "bignumber.h"

using namespace std;

int main()
{
    cout << "Enter factorial" << endl;
    int number;
    cin >> number;

    BigNumber bign(number);

    while(number > 1)
    {
        number--;
        bign.multiply(number);
    }

    bign.writeNumber();
    return 0;
}
