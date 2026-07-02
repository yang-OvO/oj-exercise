class Solution {
public:
    static int Popcnt(uint32_t n)
    {
        // 软件实现popcnt
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }

    template <bool UseHardwarePopcount = true>
    int HammingWeightImpl(uint32_t n)
    {
        if constexpr (UseHardwarePopcount)
            return std::popcount(n);
        else
            return Popcnt(n);
    }

    int HammingWeightImpl2(uint32_t n)
    {
        int res = 0;

        for (int i = 0; i < 32; i++) {
            if (n & (1u << i)) {
                res++;
            }
        }
        return res;
    }

    int HammingWeightImpl3(uint32_t n)
    {
        int res = 0;

        while (n) {
            n = n & (n-1);
            res++;
        }

        return res;
    }

    int hammingWeight(uint32_t n)
    {
        return HammingWeightImpl3(n);
    }
};