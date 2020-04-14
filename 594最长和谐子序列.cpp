和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。

现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。

示例 1:

输入: [1,3,2,2,5,2,3,7]
输出: 5
原因: 最长的和谐数组是：[3,2,2,2,3].
说明: 输入的数组长度最大不超过20,000.

题解：
//1.用一个unordered_map存储状态，然后看num-1和num+1的值加起来是多少；
//这样解会比较慢
int findLHS(vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto num : nums)
        m[num]++;
    int maxNum = 0, count = 0;
    for (auto num : nums) {
        if(!m[num-1] && !m[num+1])
            count = 0;
        else
            count = m[num - 1] > m[num + 1] ? m[num] + m[num - 1] : m[num] + m[num + 1];
        maxNum = max(count, maxNum);
    }
    return maxNum;
}

//2.sort排序后，用指针表示，计算指针之间的位置之差：
int findLHS(vector<int> &nums) {
    if (nums.size() <= 1)
        return 0;
    sort(nums.begin(), nums.end());
    int l = 0, r = 1, maxNum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int j = i + 1;
        while (j < nums.size() && nums[j] - nums[i] <= 1)
            ++j;
        if (nums[j - 1] - nums[i] == 1)
            maxNum = max(maxNum, j - i);
    }
    return maxNum;
}
