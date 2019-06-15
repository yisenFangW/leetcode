给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

题解：
//很明显的动态规划题，但是自己想，想不到递推公式，只能参考别人写的递推公式
//当s[i] == s[j]时，dp[i][j] = dp[i+1][j-1]+2; 当s[i] != s[j]时，dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//这道题开始在写的时候还出现了一点问题，我写的i循环从0开始，然后结果就有错误，动态规划坐标型，
//在循环时，何时从0开始循环，何时从最大开始循环？？？？
int longestPalindromeSubseq(string s) {
	if (s.empty())
		return 0;
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	int maxLen = 1;
	for (int i = s.size()-1; i >= 0; --i) {
		dp[i][i] = 1;
		for (int j = i + 1; j < s.size(); ++j) {
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			maxLen = max(maxLen, dp[i][j]);
		}
	}
	//for (auto i : dp) {
	//	for (auto j : i)
	//		cout << j << " ";
	//	cout << endl;
	//}
	return maxLen;
}
