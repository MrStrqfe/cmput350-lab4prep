#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);

    uint64_t result = 0;
    uint64_t targetPos = 0;

    while (input != 0 && targetPos < 64) {
        // Check if the least significant bit is 1
        if ((input & 1ULL) == 1ULL) {
            result |= (1ULL << targetPos);
        }

        // Shift input to inspect the next bit
        input >>= 1;

        // Move to the next destination position
        targetPos += scale;
    }
    return result;  // replace this with your impl!
}

int main() {
    // test here...
    // check the given prompt
    assert(expand(0b1111, 3) == 0b001001001001);
    assert(expand(0b0101, 2) == 0b00010001);

    // Check scale == 1 (should be no change)
    assert(expand(0, 1) == 0);
    assert(expand(0x123456789ABCDEF0, 1) == 0x123456789ABCDEF0);

    // Test for scale >= 64, only bit 0 can fit in the 64-bit result
    assert(expand(0b11, 64) == 1);
    assert(expand(0b10, 64) == 0); 

    return 0;
}
