给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

题解：
//这题是找出与target最接近的三个数，首先那道题不是很清楚解题的思路，看了一下网上别人的解题方法，先将数组排序，然后确定一个数的位置
//这个确定的数的位置，从左往右走，然后设置left和right指针，一共可以确定三个数的位置，最后记录下差值最小的一个数值；
//i从0开始，left=i+1,right=nums.size()-1;用while循环的判断条件是left<right，又不一定是left要在i左边，right要在i右边嘛，都是可以灵活安排的；
//重新写第二遍，思路还是不是很清晰，要注意看这题；

int threeSumClosest(vector<int>& nums, int target) {
    int diff = INT_MAX;
    int sum = INT_MAX;
    int res = INT_MAX;
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size();++i){
        int left = i+1, right = nums.size()-1;
        while(left < right){
            sum = nums[i]+nums[left]+nums[right];
            if(sum == target)
                return target;
            if(diff > abs(target - sum)) {
                res = sum;
                diff = abs(target - sum);
            }
            if(sum < target)
                ++left;
            else
                --right;
        }
    }
    return res;
}
