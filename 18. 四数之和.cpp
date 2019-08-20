给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

题解：
//1.注意这题的方法哦，因为是四个数，所有设置了i,j，然后用left和right遍历后面的，这样就能够得到四个数的和
//但是在这里，这个程序还有许多需要注意的地方，比如left>j+1时，判断是否有重复的数，如果有，就直接continue;
//用一个set去冲，最后将set的值，付给vector<vector<int>>,当sum==num[i]+nums[j]+nums[left]+nums[right];
//相当的话，需要++left,--right;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if(nums.size()<4) return {};
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-3;++i){
        for(int j=i+1;j<nums.size()-2;++j){
            if(j>i+1 && (nums[j]==nums[j-1])) continue;
            int left = j+1, right = nums.size()-1;
            while(left < right){
                int sum = nums[i]+nums[j]+nums[left]+nums[right];
                if(sum == target){
                    s.insert(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                    ++left; --right;
                }
                else if(sum > target)  --right;
                else ++left;
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}
