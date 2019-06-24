给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

题解：
//这题和78题很类似，加了一个条件就是去除结果中的重复元素
//开始第一遍写是在递归函数中写一个临时vector<int> tmp = out,然后排序插入到set中，那样就是会比较慢，直接对原nums排序即可
void subDup(vector<int>& nums, int start, set<vector<int>>& uset, vector<int>& out) {
	for (int i = start; i < nums.size(); ++i) {
		out.push_back(nums[i]);
		uset.insert(out);
		subDup(nums, i + 1, uset, out);
		out.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res(1);
	set<vector<int>> uset;
	vector<int> out;
	sort(nums.begin(), nums.end());
	subDup(nums, 0, uset, out);
	for (auto i = uset.begin(); i != uset.end(); ++i)
		res.push_back(*i);
	return res;
}
