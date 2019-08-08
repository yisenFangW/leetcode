给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

题解：
//这题首先拿到题，排除法，可以快速判断题目是不是错的，因为要左右相等，所以左边加右边一定是偶数，可以计算得到总和为sum,
//然后就是一题看题目中的数能不能凑成target = sum>>1的值了，比较适合的就是用动态规划来求解；
//这题的动态规划还是很难想到的啊，转移方程；
//遍历nums中的数，nums[i]加上之后，可以组成nums[i]~target的值，若所以从target往nums[i]遍历，然后判断
//转移方程就是： dp[i] = dp[i] || dp[i - num];
bool canPartition(vector<int>& nums) {
    if(nums.empty()) return false;
    int sum = 0;
    for(auto num : nums) sum += num;
    if(sum & 1) return false;
    int target = sum >> 1;
    vector<bool> dp(target, false);
    dp[0] = true;
    for(auto num : nums){
        for(int i=target;i>=num;i--){
            dp[i] = dp[i] || dp[i - num];
        }
    }
    return dp[target];
}
