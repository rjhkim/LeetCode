class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t counter = 0;

        uint32_t temp = n;

        while (temp != 0) {
            uint32_t current = (temp) & 1;
            if (current == 1) {
                counter++;
            }
            temp >>= 1;
        }

        return counter;
    }
};