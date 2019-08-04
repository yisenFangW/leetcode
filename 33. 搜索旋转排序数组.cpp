假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

题解：
//题目既然都已经说到了是O(log n)的时间复杂度，那么在数组中，肯定是用的二分法无疑了，主要就是这题，如何确定二分收敛的方向；
//开始也没看出来规律是什么，然后通过率大概是170/190,看了别人总结的规则为，
//若中间值小于右侧，则右侧是有序的，若中间值大于右侧，则左侧是有序的。   有了这个规律就很好写了，一道二分搜索；

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while(left <= right){
        if(nums[left] == target)
            return left;
        if(nums[right] == target)
            return right;
        int mid = left + (right-left)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < nums[right]){
            if(target > nums[mid] && target < nums[right])
                left = mid+1;
            else
                right = mid-1;
        }else{
            if(target > nums[left] && target < nums[mid])
                right = mid-1;
            else
                left = mid+1;
        }
    }
    return -1;
}

