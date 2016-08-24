#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include <vector>
#include <iostream>

using namespace std;

class BigNumber
{
private:
    std::vector<int> array;
    void setVector(int number);
public:
    BigNumber();
    BigNumber(int number);
    void multiply(int number);
    void writeNumber();
    static int lenght(int number);
};

#endif // BIGNUMBER_H
