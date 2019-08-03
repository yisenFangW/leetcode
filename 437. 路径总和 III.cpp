给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

题解：
//这题要考虑的问题是所有的节点都要作为根节点，然后往下遍历，如果是大小等于sum则加一，若不是则继续遍历，树的递归遍历常用写法，也是要注意的；
class Solution {
public:
    int pathSum(TreeNode* root, int sum, int &target){
        if(!root) return 0;
        sum += root->val;
        return (sum == target)+pathSum(root->left,sum, target)+pathSum(root->right,sum, target)
               +pathSum(root->left, 0, target)+pathSum(root->right, 0, target);
    }

    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSum(root, 0, sum); //+ pathSum(root->left, 0, sum) + pathSum(root->right, 0, sum);
    }
};
