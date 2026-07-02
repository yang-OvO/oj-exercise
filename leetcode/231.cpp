class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0) {
            return false;
        }

        return ((unsigned)n & ((unsigned)n-1)) == 0;
    }
};