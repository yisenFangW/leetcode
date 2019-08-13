假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

题解：
//这题就是要判断排序的顺序，因为中间有个转折，需要注意这个点；
//如果左侧小于右侧，那左侧和右侧肯定是升序排列的，返回最左侧的值就OK
//如果是左侧大于右侧，则要对中间值进行判断，这里一定要注意特殊情况的判断啊，因为就是特殊情况搞了半天；
int findMin(vector<int>& nums) {
   int left = 0, right = nums.size()-1;
   if(nums.size() == 1) return nums[0];
   while(left <= right){
       if(nums[left] <= nums[right])
           return nums[left];
       int mid = left + (right - left) / 2;
       //注意判断这里if中的判断条件
       if(nums[mid] >= nums[left])
           left = mid+1;
       else
           //这里的right不能是mid-1不然就会出错，两个数或者三个数的时候
           right = mid;
   }
   return nums[left];
}
