给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

题解：
// 简单题，开始拿到题直接写，双层嵌套for循环，没做任何判断
bool containsNearbyDuplicate(vector<int> &nums, int k) {
    if (nums.size() < 2 || k <= 0)
        return false;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size() && (j - i) <= k; ++j) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}
//然后这样的话，是没有把没有重复的元素考虑进去，最后一个通不过，加了一个hashmap做判断，再进行循环处理；增大了内存消耗
bool containsNearbyDuplicate(vector<int> &nums, int k) {
    if (nums.size() < 2 || k <= 0)
        return false;
    unordered_map<int, int> m;
    for (auto num : nums)
        ++m[num];
    for (int i = 0; i < nums.size(); ++i) {
        if (m[nums[i]] < 2)
            continue;
        for (int j = i + 1; j < nums.size() && (j - i) <= k; ++j) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}
