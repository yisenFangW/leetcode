给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

题解：
//这题的思路就是看怎么记录下某个值是否出现过，用本来的数组记录，如果出现过这个数，就将这个数的值变成负数，
//第二遍遍历的时候，检查这个数是否为负数，如果为正数，则说明没有出现过，加到输出数组中；
vector<int> findDisappearedNumbers(vector<int>& nums) {
    if(nums.empty()) return {};
    vector<int> res;
    for(auto num : nums){
        int index = abs(num) - 1;
        nums[index] = nums[index]>0?-nums[index]:nums[index];
    }
    for(int i=0;i<nums.size();++i) {
        if(nums[i] > 0)
            res.push_back(i+1);
    }
    return res;
}
