给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

输入: 二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

题解：
//拿到这题，首先将后面的数加到前面的数，就是传一个sum，然后以右中左的顺序将各个节点的值加到sum上，每个数加上上一个节点传过来的sum；
void rightTravel(TreeNode* root, int sum){
    if(!root) return;
    rightTravel(root->right, sum);
    root->val += sum;
    sum = root->val;
    rightTravel(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    if(!root) return nullptr;
    int sum = 0;
    rightTravel(root, sum);
    return root;
}
