给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

题解：
//这题很明显就是一个二分法的写法，需要注意的就是target<nums[0]与target>nums.back()的情况，单纯的二分法写法
int searchInsert(vector<int>& nums, int target) {
	if (nums.empty() || nums[0] > target)
		return 0;
	if (nums.back() < target)
		return nums.size();
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}
