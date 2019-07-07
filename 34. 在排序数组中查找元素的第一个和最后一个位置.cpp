给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

题解：
//拿到本题说时间复杂度为O(logn)，而且还是排序数组题，第一想法肯定是二分法；
//注意在写的时候的特殊情况，比如[1],1,这个就要让left<=right,而且要判断left==right的情况；
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty() || target<nums.front() || target > nums.back())
        return vector<int> {-1,-1};
    int left = 0, right = nums.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(left == right && nums[left]!= target)
            break;
        if(nums[mid] == target){
            int i = mid,j = mid;
            while(i>=left && nums[i] == target)
                --i;
            while(j<=right && nums[j] == target)
                ++j;
            return vector<int> {i+1,j-1};
        }
        else if(nums[mid] > target)
            right = mid;
        else
            left = mid+1;
    }
    return vector<int> {-1,-1};
}
