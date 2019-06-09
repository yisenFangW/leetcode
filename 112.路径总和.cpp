给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

解题：
//简单题，跟路径总和II的题目类型完全一致，因此写起来比较方便
//注意辅助函数返回bool，就让最后返回左右子树的或（有一个真即为真）
bool hasPath(TreeNode* node, int sum, int pathSum) {
	if (!node)
		return false;
	pathSum += node->val;
	if (pathSum == sum && !node->left && !node->right)
		return true;
	return hasPath(node->left, sum, pathSum) || hasPath(node->right, sum, pathSum);
}

bool hasPathSum(TreeNode* root, int sum) {
	return hasPath(root, sum, 0);
}
