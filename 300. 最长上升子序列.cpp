给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

题解：
//1.时间复杂度为O(n2);
int lengthOfLIS(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> dp(nums.size(), 1);
	int maxNum = 1;
	for (int i = 1; i < nums.size(); ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] > maxNum)
					maxNum = dp[i];
			}
		}
	}
	return maxNum;
}

//2.看的别人想法，写出来的，用二分法写的，设计一个辅助数组dp，当nums[i]小于dp[0]，直接替换dp[0] = nums[i];
//当nums[i] > dp.back()时，dp.push_back(nums[i]),当在两个之间时，用二分法找到第一个不比nums[i]小的元素替换掉
//最后求dp数组的长度即为所求。
int lengthOfLIS(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> dp{nums[0]};
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] < dp.front()) { 
			dp[0] = nums[i];
			continue;
		}
		if (nums[i] >= dp.back())
			dp.push_back(nums[i]);
		int left = 0, right = dp.size()-1;
		while (left != right) {
			int mid = left + (right - left) / 2;
			if (nums[i] > dp[mid])
        //注意这个地方为left = mid + 1;
				left = mid + 1;
			else
				right = mid;
		}
		dp[right] = nums[i];
	}
	return dp.size();
}

//3.也可以用lower_bound()函数进行求解，lower_bound()函数的意思是找出数组中第一个不比所找元素小的元素，返回一个迭代器。
//(注意lower_bound()函数的使用)
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp;
	for (int i = 0; i < nums.size(); ++i) {
		int left = 0, right = dp.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (dp[mid] < nums[i]) left = mid + 1;
			else right = mid;
		}
		if (right >= dp.size()) dp.push_back(nums[i]);
		else dp[right] = nums[i];
	}
	return dp.size();
}
