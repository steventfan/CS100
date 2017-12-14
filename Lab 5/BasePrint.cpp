#include "BasePrint.h"

void DoublePrint::print()
{
    std::cout << value;
}

void HexPrint::print()
{
    //std::cout << std::hexfloat;
    std::cout << value;
}

void BinaryPrint::print()
{
    std::bitset<16> number(value);
    std::cout << number;
}