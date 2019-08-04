翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。

题解：
//这题就是简单的把二叉树的左子树和右子树换个位置，然后继续递归遍历，比较传统；
TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    TreeNode* tmp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(tmp);
    return root;
}
