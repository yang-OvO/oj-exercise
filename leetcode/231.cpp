class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        // return has_single_bit((uint32_t)n);
        return n > 0 && (((unsigned)n & ((unsigned)n-1)) == 0);
    }

    uint32_t FloorPowerOfTwoImpl1(uint32_t n)
    {
        if (n == 0) return 0;

        return 1u << (31 - countl_zero(n));
    }

    uint32_t FloorPowerOfTwoImpl2(uint32_t n)
    {
        if (n == 0) return 0;

        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);

        return n - (n >> 1);
    }

    uint32_t NextPowerOfTwoImpl1(uint32_t n)
    {
        if (n == 0) return 1;

        return 1ULL << (32 - countl_zero(n-1));
    }

    uint32_t NextPowerOfTwoImpl2(uint32_t n)
    {
        if (n == 0) return 1;

        n--;
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);

        return n + 1u;
    }

};