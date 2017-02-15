/* Generate binary numbers from 1 to n */

#include <iostream>
#include <bitset>
#include <string>
#include <queue>

const std::bitset<16> one(1);

void genBinNumbers(std::size_t limit);

int main(void) {
    genBinNumbers(10);

    return 0;
}

void genBinNumbers(std::size_t limit) {
    std::bitset<16> num(one);
    std::queue<std::bitset<16> > numbers;
    numbers.push(num);

    for(std::size_t index = 0; index != limit; ++index) {
        num = numbers.front();
        numbers.pop();

        std::cout << num << std::endl;

        numbers.push(num <<= 1);
        numbers.push(num | one);
    }
}
