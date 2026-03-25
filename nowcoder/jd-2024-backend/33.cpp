#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    vector<int> subnode;    // 存放子节点的索引
    int color{};
};

void GetColors(const TreeNode& n, const vector<TreeNode>& t, vector<int>& colors)
{
    // 添加当前节点的颜色，然后把子树的颜色添加进来
    colors.emplace_back(n.color);
    for (int sub_n: n.subnode) {
        GetColors(t[sub_n], t, colors);
    }
}

void GetMaxColor(const vector<int>& colors, set<int>& max_color)
{
    // 使用哈希表统计每个颜色出现的次数
    unordered_map<int, int> countMap;
    for (int color : colors) {
        countMap[color]++;
    }
    
    // 找出最大出现次数
    int maxCount = 0;
    for (auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    }
    
    // 将所有出现次数等于最大次数的颜色加入结果
    for (auto& pair : countMap) {
        if (pair.second == maxCount) {
            max_color.insert(pair.first);
        }
    }
}

int GetXOR(const TreeNode& n, const vector<TreeNode>& t, const set<int>& max_color)
{
    int res = 0;
    for (int sub_n: n.subnode) {
        res ^= GetXOR(t[sub_n], t, max_color);
    }
    if (max_color.find(n.color) == max_color.end()) {
        // 不在集合里，那么吃该糖果
        res ^= n.color;
    }
    return res;
}

void MaxXOR(const TreeNode& n, const vector<TreeNode>& t, int& res)
{
    if (n.subnode.empty()) {
        // 没有子节点，只有这一个节点，结果为0
        return;
    }

    // 查找子树的所有糖果颜色的异或和
    for (int sub_n: n.subnode) {
        MaxXOR(t[sub_n], t, res);
    }
    // 查找该树的所有糖果颜色
    vector<int> colors;
    GetColors(n, t, colors);
    // 寻找出现次数最多的颜色的糖果
    set<int> max_color;
    GetMaxColor(colors, max_color);
    // 得到该树的颜色的异或和
    int this_tree_xor_sum = GetXOR(n, t, max_color);
    if (this_tree_xor_sum > res) {
        res = this_tree_xor_sum;
    }
}

void buildTree(vector<TreeNode>& t, int n) {
    vector<vector<int>> adj(n + 1);
    
    // 读取所有边并构建邻接表
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 使用DFS从根节点1开始构建树
    vector<bool> visited(n + 1, false);
    
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                t[node].subnode.push_back(neighbor);
                dfs(neighbor);
            }
        }
    };
    
    dfs(1);
}

int main() {
    // 输入
    int n;
    cin >> n;
    vector<TreeNode> t(n+1);
    for (int i = 0; i < n; i++) {
        cin >> t[i+1].color;
    }
    buildTree(t, n);
    // 处理
    int res = 0;
    MaxXOR(t[1], t, res);
    // 输出
    cout << res << "\n";
}
// 64 位输出请用 printf("%lld")
