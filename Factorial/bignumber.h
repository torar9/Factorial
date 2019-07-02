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
    void setArray(int number, int *array);
    void setVector(int number, vector<int> &array);
    void fixVector(vector<int> &array);
public:
    BigNumber();
    BigNumber(int number);
    ~BigNumber();
    
    void multiply(int number);
    void writeNumber();
    
    static int length(int number);
};

#endif // BIGNUMBER_H
