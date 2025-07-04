#include <iostream>
#include <bit>
#include <bitset>
#include <iomanip>

int test() {
    std::setprecision(6);
    float f = 23.45f;
    // Use std::bit_cast to reinterpret the bits of the float as an integer
    int i = std::bit_cast<int>(f); 

    std::cout << "Original float: " << f << std::endl;
    std::cout << "Integer representation of the float's bit pattern: " << i << std::endl;

    std::bitset<32> b(i);
    std::cout << b << '\n';

    uint32_t rawBits = std::bit_cast<uint32_t>(f);
    std::bitset<32> fb(rawBits);
    std::cout << fb << '\n';

    return 0;
}