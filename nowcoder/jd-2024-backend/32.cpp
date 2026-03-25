#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct StringComparator
{
    unordered_map<char, int> rank_table;

    bool operator()(const string& lhs, const string& rhs) const
    {
        int n = min(lhs.size(), rhs.size());
        for (int i = 0; i < n; i++) {
            if (rank_table.at(lhs[i]) < rank_table.at(rhs[i])) {
                return true;
            } else if (rank_table.at(rhs[i]) < rank_table.at(lhs[i])) {
                return false;
            } else {
                continue;
            }
        }
        if (lhs.size() == rhs.size()) {
            return false;
        }
        return lhs.size() < rhs.size();
    }
};

int main() {
    // 输入
    StringComparator sc;
    for (int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        sc.rank_table.insert({c, i});
    }
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    // 处理
    sort(strings.begin(), strings.end(), sc);

    // 输出
    for (int i = 0; i < n; i++) {
        cout << strings[i] << "\n";
    }
}
// 64 位输出请用 printf("%lld")
