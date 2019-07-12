计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

题解：
//1.这个重点就是如何找到所有的左叶子节点，首先是左节点，其次是左叶子节点，所以要有两个判断条件；
//看题解是用一个标志位标志是否是左节点，然后判断是否是叶节点，即判断其是否有子节点；
void inTraTree(TreeNode* root, bool flag, int& res){
    if(!root)
        return;
    if(!root->left && !root->right && flag){
        res+=root->val;
    }
    inTraTree(root->left, true, res);
    inTraTree(root->right, false, res);
}

int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    if(!root || (!root->left && !root->right)) return 0;
    inTraTree(root->left, true, res);
    inTraTree(root->right, false, res);
    return res;
}

//2.更加简洁的写法，是判断这个节点的左子节点，不是判断这个节点的本身，也不用多余的res；
int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    if(root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
}
