你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

解题：这题和打家劫舍I的不同点在于所有家形成了一个环状，然后第一家不能和最后一家同时偷，但是怎么判断第一家和最后一家同时偷，
这就是一个比较麻烦的问题，自己写了一版，没有通过所有的测试用例，{1,2,9,4},我的判断是dp[2] != dp[1] && dp[nums.size() - 1] != dp[nums.size() - 2]
这样判断并不合理，因为可能dp[2]取了，但最后一个值并没有用。
//1.自己写的没通过的版本：
void rob2(vector<int>& nums, vector<int>& dp) {
	for (int i = 2; i < nums.size(); ++i)
		dp[i] = max((dp[i - 2] + nums[i]), dp[i - 1]);
}

int rob(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int res = 0;
	if (nums.size() <= 3) {
		for (int i = 0; i < nums.size(); ++i) {
			res = max(res, nums[i]);
		}
		return res;
	}
	vector<int> dp(nums.size(),0);
	dp[0] = nums[0], dp[1] = nums[1];
	rob2(nums, dp);
	if (dp[2] != dp[1] && dp[nums.size() - 1] != dp[nums.size() - 2]) {
		if (dp[0] <= dp[nums.size() - 1])
			nums.erase(nums.begin());
		else
			nums.erase(nums.end());
		rob2(nums, dp);
	}
	return dp[nums.size() - 1];
}
//2.参考博客的版本，别人的想法是将第一家和最后一家分别去掉，然后各求一个版本，得到的最大值，即为所求。
//自己写的版本开始遇到了一个问题，开始在rob2()中，我将dp[1] = nums[1],这样写是不对的，分析一下，当dp[1]时，可以偷nums[0],也可以是dp[1]
//所以根据情况，dp[1] = max(nums[0], nums[1]);
int rob2(vector<int>& nums) {
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0], dp[1] = max(nums[1], nums[0]);
	for (int i = 2; i < nums.size(); ++i)
		dp[i] = max((dp[i - 2] + nums[i]), dp[i - 1]);
	return dp.back();
}

int rob(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int res = 0;
	if (nums.size() <= 3) {
		for (int i = 0; i < nums.size(); ++i) {
			res = max(res, nums[i]);
		}
		return res;
	}
	vector<int> nums1(nums.begin() + 1, nums.end());
	vector<int> nums2(nums.begin(), nums.end() - 1);
	return max(rob2(nums1), rob2(nums2));
}

