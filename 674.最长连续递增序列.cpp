给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。

题解：（简单题）
//简单题思路很清晰
//1.第一思想，动态规划
int findLengthOfLCIS(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> dp(nums.size(), 1);
	int maxNum = 1;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] > nums[i - 1]) {
			dp[i] = dp[i - 1] + 1;
			if (dp[i] > maxNum)
				maxNum = dp[i];
		}
	}
	return maxNum;
}

//2.O(1)空间复杂度
int findLengthOfLCIS(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int cnt = 1, res = 1, cur = nums[0];
	for (auto num : nums) {
		if (num > cur) ++cnt;
		else cnt = 1;
		res = max(res, cnt);
		cur = num;
	}
	return res;
}
