给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

解题：
//受启发，返回所有路径的题目一般都是用递归，特别此题还是树的题目，更是用递归实现了，但是在开始写的时候，递归写的跟数组一样
//写的不好，然后重新了一下，参考了一下，最后通过。

void path(TreeNode* node, int sum, int pathSum, vector<int> &out, vector<vector<int>> &res) {
	if (!node || pathSum >sum)
		return;
	pathSum += node->val;
	out.push_back(node->val);
	if (pathSum == sum && !node->left && !node->right) {
		res.push_back(out);
    //注意这个地方为什么不能用return,用了return答案就有些不对
		//return;
	}
	path(node->left, sum, pathSum, out, res);
	path(node->right, sum, pathSum, out, res);
  //注意这里要进行pop_back()将node结点取出，不然一直不取出，out大小就一直只会增长，结果不对。
	out.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	vector<int> out;
	path(root, sum, 0, out, res);
	return res;
}
