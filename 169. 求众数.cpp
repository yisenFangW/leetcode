给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

题解：
//今天从X1换到Mac，各种操作都不是很熟，但是已经感觉到Mac要比X1爽很多了，浪费了很多时间，晚上都没有看书，罪恶啊！！！
//做一题简单题；
//1.排序后直接取中间数
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

//2.将第一个假设为超过一半的数字，然后便利，如果和变量相同，则计数加1，否则计数减1，若计数变成0了，换为现在的这个数为假设一半的数字
//O(n)时间复杂度，O(1)空间复杂度；
int majorityElement(vector<int>& nums) {
    int tmp  = nums[0];
    int count = 1;
    for(int i=1;i<nums.size();++i){
        if(nums[i] == tmp) ++count;
        else --count;
        tmp = count?tmp:nums[i];
    }
    return tmp;
}
