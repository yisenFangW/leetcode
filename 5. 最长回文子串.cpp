给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

题解：
//1.暴力解法：O(n*n)
void searchPalindrome(string s, int left, int right, int &start, int &maxLen) {
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		--left;
		++right;
	}
	if (maxLen < right - left - 1) {
		start = left + 1;
		maxLen = right - left - 1;
	}
}

string longestPalindrome(string s) {
	if (s.size() < 2) return s;
	int n = s.size(), maxLen = 0, start = 0;
	for (int i = 0; i < n - 1; ++i) {
		searchPalindrome(s, i, i, start, maxLen);
		searchPalindrome(s, i, i + 1, start, maxLen);
	}
	return s.substr(start, maxLen);
}
//动态规划，dp[i][j]表示在数组i~j范围内是否为回文子串
//当i==j时，只有一个字符，dp[i][j] = 1;当i == j+1时，此时字符串有两个字符，所以当s[i] == s[j]，为回文子串
//当i-j>2时判断s[i] == s[j]，且dp[j+1][i-1] == 1时，才为回文子串
//测试动态规划时间复杂度还要高一些，将vector<vector<int>>改为int[][],空间复杂度减小了不少。
string longestPalindrome(string s) {
	if (s.empty())
		return "";
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	int maxLen = 1, start = 0;
	for (int i = 0; i < s.size(); ++i) {
		dp[i][i] = 1;
		for (int j = 0; j < i; ++j) {
			dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
			if (dp[j][i] && i - j + 1 > maxLen) {
				start = j;
				maxLen = i - j + 1;
			}
		}
	}
	return s.substr(start, maxLen);
}
