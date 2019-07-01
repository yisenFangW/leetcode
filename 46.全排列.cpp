给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

题解：
//这题首先拿到题目，就应该是要想到是用递归去做的，想到可能还有动态规划能做这样的题目。想道回溯法，但是没有实际动手去做，因为
//不知道具体的操作是什么，了解到可以用一个visted数组去标记遍历过的和没有遍历过的，就是很明显的回溯法做法；
void permuteDFS(vector<vector<int>> &res, vector<int>& nums, int level, vector<int> &visted, vector<int> &out) {
	if (level == nums.size()) {
		res.push_back(out);
		return;
	}
	for (int i = 0; i < nums.size(); ++i) {
		if (visted[i] == 1)
			continue;
		visted[i] = 1;
		out.push_back(nums[i]);
		permuteDFS(res, nums, level + 1, visted, out);
		out.pop_back();
		visted[i] = 0;
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.empty())
		return res;
	vector<int> visted(nums.size(), 0);
	vector<int> out;
	permuteDFS(res, nums, 0, visted, out);
	return res;
}
