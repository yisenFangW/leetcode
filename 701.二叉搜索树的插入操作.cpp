给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

题解：
//这题本是很简单的一道二叉搜索树的递归问题，都被我自己给绕糊涂了，因为返回值为TreeNode*,因此在判断
//的时候需要给左子树右子树赋值等操作；

class Solution {
public:
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(root->val > val) root->left = insertIntoBST(root->left, val);
    if(root->val < val) root->right = insertIntoBST(root->right, val);
    return root;
}
};
