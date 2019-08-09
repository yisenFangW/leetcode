给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

题解：
//这题首先是想到的用除法，但是已经说明不让啦，而且可能会出现存在0的情况，
//然后就是常规的解法，两层循环，这样也太水了，明显会过不了，
//最后还是想不到该怎么做，看了别人的题解，建立从前面往后面，和从后面往前面的数组记录乘的数值，然后要哪个，就把前后的乘起来就得到最后的值

vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.empty()) return {};
    vector<int> lefRes(nums.size(), 1), rightRes(nums.size(), 1), res(nums.size(), 1);
    for(int i=0;i<nums.size()-1;++i)
        lefRes[i+1] = nums[i]*lefRes[i];
    for(int i = nums.size()-1;i>0;--i)
        rightRes[i-1] = rightRes[i]*nums[i];
    for(int i=0;i<nums.size();++i)
        res[i] = lefRes[i]*rightRes[i];
    return res;
}
