给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

题解：跟最长连续上升子数组是一类题目（动态规划解法）(这样写时间复杂度较高O(n*n))
//1.因为这个是无序的，所以先排下序，先用第一个数字排，第一个数字一样，用第二个数字排（其实这题可以随便排）
//sort(envelopes.begin(), envelopes.end(), [](const vector<int> &v1, const vector<int> &v2)
//	{if (v1.front() == v2.front()) return v1.back() < v2.back();
int maxEnvelopes(vector<vector<int>>& envelopes) {
	if (envelopes.empty())
		return 0;
	int maxLen = 1;
	sort(envelopes.begin(), envelopes.end(), [](const vector<int> &v1, const vector<int> &v2)
	{if (v1.front() == v2.front()) return v1.back() < v2.back();
		else return v1.front() < v2.front(); });
	vector<int> dp(envelopes.size(), 1);
	for (int i = 0; i < envelopes.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxLen = max(maxLen, dp[i]);
	}
	return maxLen;
}

//2.更加快速的方法，暂时没有没有想到哇，看看别人写的思路
