#include <cstdio>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    // 输入
    int n;
    vector<int> sequence;
    cin >> n;
    sequence.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // 处理
    vector<int> sigma_seq(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sigma_seq[i] = sequence[i];
        } else {
            sigma_seq[i] = sigma_seq[i-1] + sequence[i];
        }
    }

    long long smallest_cost = numeric_limits<long long>::max();
    // 长度为n的序列存在n-1个切割点
    for (int i = 0; i < n - 1; i++) {
        // 左序列为[0, i]
        long long left_sum = sigma_seq[i];
        // 右序列为[i+1, n-1]
        long long right_sum = sigma_seq[n-1] - sigma_seq[i];
        if (left_sum * right_sum < smallest_cost) {
            smallest_cost = left_sum * right_sum;
        }
    }

    printf("%lld\n", smallest_cost);
}
// 64 位输出请用 printf("%lld")</long></int></int></limits></vector></iostream></cstdio>
