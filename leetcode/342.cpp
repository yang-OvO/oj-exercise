class Solution {
public:
    bool isPowerOfFour(int n)
    {
        // if (n <= 0) {
        //     return false;
        // }

        // while (n && n % 4 == 0) {
        //     n /= 4;
        // }

        // return n == 1;

        // 4的幂一定是2的幂，二进制表示只存在一个1
        // 4的幂中的1一定在第3位或者第5位等等（0-31位）
        return n > 0 &&
            ((uint32_t)n & ((uint32_t)n-1)) == 0 &&
            ((uint32_t)n & 0xAAAAAAAA) == 0;
    }
};
