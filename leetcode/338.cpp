class Solution {
public:
    static int Popcnt(unsigned n)
    {
        // 软件实现popcnt
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }

    vector<int> CountBitsStd(int n)
    {
        // 使用builtin popcount
        // 通常会被编译器优化成硬件指令
        return std::views::iota(0, n+1)
            | std::views::transform(std::popcount<unsigned>)
            | std::ranges::to<std::vector>();
    }

    vector<int> CountBitsImpl1(int n)
    {
        return std::views::iota(0, n+1)
            | std::views::transform(Popcnt)
            | std::ranges::to<std::vector>();
    }

    vector<int> countBits(int n)
    {
        return CountBitsImpl1(n);
    }
};