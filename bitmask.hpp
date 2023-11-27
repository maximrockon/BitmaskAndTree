#ifndef BITMASK_HPP
#define BITMASK_HPP
#include <concepts>
#include <iostream>
#include <bitset>

template <typename T>
concept BitmaskConcept = requires(T t) {
    { t.size() } -> std::convertible_to<std::size_t>;
};

template <BitmaskConcept BitmaskType>
bool isBitmaskCorrect(const BitmaskType& mask) {
    if (mask.size() != 32) {
        return false;
    }

    bool wasZeroPresent = false;
    
    for (size_t i = 0; i < mask.size(); ++i) {
        bool bit  = mask[i];
        if constexpr (std::is_same_v<BitmaskType, std::bitset<32>>) {
            bit = mask[mask.size() - 1 - i];
        }
        // use conjunction to check the presence of zeros
        // in the considered part of the string
        wasZeroPresent |= !bit;
        // if zero was present and current bit is 1
        // then this bitmask is incorrect
        if (wasZeroPresent && bit) {
            return false;
        }
    }
    
    return true;
}

template <BitmaskConcept BitmaskType>
void printResults(const BitmaskType& mask) {
    std::cout << "mask: ";
    for (size_t i = 0; i < mask.size(); ++i) {
        bool bit = mask[i];
        if constexpr (std::is_same_v<BitmaskType, std::bitset<32>>) {
            bit = mask[mask.size() - 1 - i];
        }
        std::cout << bit << ' ';
    }
    std::cout << "\nresult: " \
        << (isBitmaskCorrect(mask) ? "correct\n\n" : "incorrect\n\n");

}

#endif