给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

题解：
题目比较简单，因为输出是唯一，首先想法用unordered_set是给每个vector容器去重，去除重复后，再判断一个set的元素是否再另一个set中
可以直接用到set的count()函数

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());
    vector<int> res;
    for(auto i : s1){
        if(s2.count(i))
            res.push_back(i);
    }
    return res;
}

