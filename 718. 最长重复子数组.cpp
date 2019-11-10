给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释: 
长度最长的公共子数组是 [3, 2, 1]。
说明:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

题解：这题还是有难度的，在做的时候，最简单的思路就是暴力解法，但是这题的暴力解法，好像时间和空间复杂度比动态规划还要好？
1.暴力求解，就是A,B互相遍历一下，看看最长的数组的长度；也没啥技术可言
int findLength(vector<int> &A, vector<int> &B) {
    int lenA = A.size(), lenB = B.size();
    int maxLen = 0;
    for (int offsize = 0; offsize < lenA; ++offsize) {
        int count = 0;
        for (int i = offsize, j = 0; i < lenA && j < lenB; ++i, ++j) {
            if (A[i] == B[j])
                ++count;
            else
                count = 0;
            maxLen = max(maxLen, count);
        }
    }
    for (int offsize = 0; offsize < lenB; ++offsize) {
        int count = 0;
        for (int j = offsize, i = 0; i < lenA && j < lenB; ++i, ++j) {
            if (A[i] == B[j])
                ++count;
            else
                count = 0;
            maxLen = max(maxLen, count);
        }
    }
    return maxLen;
}

2.动态规划的解法，动态规划主要是找到动态规划的递归方程，这题开始没想到动态规划，看了别人的题解，才想起来
   3 1 2
1  0 1 0
2  0 0 2
2  0 0 1
从上面的这个可以看出，dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;的递归方程
动态规划写起来也比较方便了，申请数组空间的时候申请大一号，因为有i-1,j-1
int findLength2(vector<int> &A, vector<int> &B) {
    int m = A.size(), n = B.size(), res = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}
