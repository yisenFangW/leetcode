给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

题解：
//这题首先拿到题后，没有什么思路，博主说遇到这种返回所有符合要求的解，基本上都是要进行递归。我本来想的是用动态规划求解，但是需要存住每一个
//数组对应的vector<vector<int>>,所以存储的量就非常大，不太可能。只能够采用递归的方法，进行求解。
//说递归，开始还是不知道该如何进行递归，这题没什么思路，都是看着别人的解答写出来的，以后需要多看看。
void combination(vector<int>& candidates, int target, int start, vector<int> &out, vector<vector<int>> &res) {
	if (target < 0)
		return;
	if (target == 0) {
		res.push_back(out);
		return;
	}
	for (int i = start; i < candidates.size(); ++i) {
		out.push_back(candidates[i]);
		combination(candidates, target - candidates[i], i, out, res);
		out.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	if (candidates.empty() && target < candidates[0])
		return res;
	vector<int> out;
	combination(candidates, target, 0, out, res);
	return res;
}
