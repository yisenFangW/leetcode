给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

解题：
//一开始拿到这个题目，首先想到的还是递归的办法，但是运行总是超时，
void sub(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res) {
	for (int i = start; i < nums.size(); ++i) {
		out.push_back(nums[i]);
		res.push_back(out);
    //因为开始这个地方传进去的一直是i,然后运行总是循环在0，没有增长，需要传进去i+1才行；
		sub(nums, i+1, out, res);
		out.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1);
	vector<int> out;
	sub(nums, 0, out, res);
	return res;
}

//飞递归的方法，在已有的每个数组后面加上新加入的数，首先传入一个[]，然后1的话[1],2的话有[],[1]变为[2],[1,2],3的话有[],[1],[2],[1,2]
//将3加入到这些数组后面，变为[3],[1,3],[2,3],[1,2,3].（实现其实并不难，难的是在想到这种方法）
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1);
	for (int i = 0; i < nums.size(); ++i) {
    //注意这个size,因为res是在变化的，所以用size记录下res的大小
		int size = res.size();
		for (int j = 0; j < size; ++j) {
      //这个实现没有用临时变量，比较节约内存，我自己写的时候用的是临时变量vector<int> tmp;
			res.push_back(res[j]);
			res.back().push_back(nums[i]);
		}
	}
	return res;
}
