给你一个大小为 m * n 的方阵 mat，方阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回方阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

 

示例 1：

输入：mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
输出：[2,0,3]
解释：
每行中的军人数目：
行 0 -> 2 
行 1 -> 4 
行 2 -> 1 
行 3 -> 2 
行 4 -> 5 
从最弱到最强对这些行排序后得到 [2,0,3,1,4]
示例 2：

输入：mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
输出：[0,2]
解释： 
每行中的军人数目：
行 0 -> 1 
行 1 -> 4 
行 2 -> 1 
行 3 -> 1 
从最弱到最强对这些行排序后得到 [0,2,3,1]
 

提示：

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] 不是 0 就是 1

//题解：用map做的，重新写了一个排序函数，注意排序函数的大小于号的书写，最后用一个vec返回，中间还是有很多细节要抓的，不然都会失败；
struct comp {
    bool operator()(const pair<int, int> &m1, const pair<int, int> &m2) {
        if (m1.second == m2.second)
            return m1.first <= m2.first;
        else
            return m1.second < m2.second;
    }
};

class Solution {
public:
vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    unordered_map<int, int> row;
    int count = 0;
    for (auto m:mat) {
         row[count] = 0;
        for (auto i:m) {
            if (i == 1) row[count]++;
            else break;
        }
        ++count;
    }
    vector<pair<int, int>> vec(row.begin(), row.end());
    ::sort(vec.begin(), vec.end(), comp());
    vector<int> res;
    for (int i = 0; i < k; ++i)
        res.push_back(vec[i].first);
    return res;
}
};
