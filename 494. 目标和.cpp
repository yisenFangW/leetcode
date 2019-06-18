给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组的长度不会超过20，并且数组中的值全为正数。
初始的数组的和不会超过1000。
保证返回的最终结果为32位整数。

题解：
//1.递归，因为时间复杂度太高，通不过
void findTarget(vector<int>& nums, int start,int S, int& res) {
	if (start == nums.size()) {
		if (S == 0)
			++res;
		return;
	}
	findTarget(nums, start + 1, S - nums[start], res);
	findTarget(nums, start + 1, S + nums[start], res);
}

int findTargetSumWays(vector<int>& nums, int S) {
	if (nums.empty())
		return 0;
	int res = 0;
	findTarget(nums, 0, S, res);
	return res;
}

//2.用数组存住数值，空间换时间（但是一直没有想通，用vector<unordered_map<int, int>>,还是有点懵逼）
int find(vector<int>& nums, int start, int S, vector<unordered_map<int, int>>& dp) {
	if (nums.size() == start) return S == 0;
	if (dp[start].count(S)) return dp[start][S];
	int cnt1 = find(nums, start + 1, S - nums[start], dp);
	int cnt2 = find(nums, start + 1, S + nums[start], dp);
	return dp[start][S] = cnt1 + cnt2;
}

int findTargetSumWays(vector<int>& nums, int S) {
	if (nums.empty())
		return 0;
	vector<unordered_map<int, int>> dp(nums.size());
	int res = 0;
	res = find(nums, 0, S, dp);
	return res;
}
