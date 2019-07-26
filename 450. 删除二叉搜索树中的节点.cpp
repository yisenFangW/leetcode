给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7

题解：
//这题有点难度，值得到时候回头反复看，开始思路是想首先找到对应的树节点，然后再找到左右子节点替换；这样还是有些问题；
//进行递归时，在替换的时候，就出现问题了
//如果左右子节点都没有，或者有一个节点为空的话，比较好操作，直接将左右子节点赋给这个节点就OK，难就难在需要调整二叉搜索树，
//调整二叉搜索树的话，首先需要找到右子树的最左节点，然后将值赋给此节点，再对右子树进行遍历，将此值删除。
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr;
    if(root->val > key) deleteNode(root->left, key);
    if(root->val < key) deleteNode(root->right, key);
    //TreeNode* node = findNode(root, key);
    if(!root->left || !root->right)
        root = (root->left)?root->left:root->right;
    else{
        TreeNode* tmp = root->right;
        while(tmp->left) tmp = tmp->left;
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
    }
    return root;
}




