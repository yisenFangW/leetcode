给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

题解：
//开始做到这题的时候被[1,2]搞的有点懵逼，然后仔细看题目，才发现，只有叶子节点才能算，然后若是右子树不存在，左子树存在，则最小的不能算作1
//所以要增加判断条件，当左子树不存在时，树的最小路径为右子树最小值+1，同理右子树不存在时也是这样；
//若都存在，则返回较小值中的一个
int minDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
