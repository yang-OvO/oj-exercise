class Solution {
public:
    static int Popcnt(uint32_t n)
    {
        // 软件实现popcnt（SWAR）
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }

    static int BrainKernighan(uint32_t n)
    {
        int res = 0;

        while (n) {
            n = n & (n-1);
            res++;
        }

        return res;
    }

    template <bool UseHardwarePopcount = true>
    vector<int> CountBitsImpl(uint32_t n)
    {
        auto popcnt = [](uint32_t x) {
            if constexpr (UseHardwarePopcount)
                return std::popcount(x);
            else
                return Popcnt(x);
        };
        return std::views::iota(0u, n+1)
            | std::views::transform(popcnt)
            | std::ranges::to<std::vector>();
    }

    vector<int> CountBitsImpl2(uint32_t n)
    {
        return std::views::iota(0u, n+1)
            | std::views::transform(BrainKernighan)
            | std::ranges::to<std::vector>();
    }

    vector<int> CountBitsImpl3(uint32_t n)
    {
        vector<int> res(n+1, 0);
        int highBit = 0;

        for (size_t i = 1; i <= n; i++) {
            if ((i & (i-1)) == 0) {
                highBit = i;
            }
            res[i] = res[i-highBit] + 1;
        }

        return res;
    }

    vector<int> CountBitsImpl4(uint32_t n)
    {
        vector<int> res(n+1, 0);

        for (size_t i = 1; i <= n; i++) {
            res[i] = res[i&(i-1)] + 1;
        }

        return res;
    }

    vector<int> countBits(uint32_t n)
    {
        return CountBitsImpl4(n);
    }
};