给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

题解：
//1.拿到这个问题，首先还是想到中旬遍历，然后存入到vector中,判断是否是递增的，若不是，则返回错误，若是则返回正确；
//但是这样做是占用空间
void isBST(TreeNode* root, vector<int>& nums){
    if(!root) return;
    isBST(root->left, nums);
    nums.push_back(root->val);
    isBST(root->right, nums);
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    vector<int> nums;
    isBST(root, nums);
    for(int i=0;i<nums.size()-1;++i){
        if(nums[i]>=nums[i+1])
            return false;
    }
    return true;
}

//2.给一个左节点和右节点的大小，若节点的大小在此范围内，则遍历左右子树，若不在此范围内，则返回错误；
//不占用内存空间，较优
class Solution {
public:
bool isBST(TreeNode* root, long maxNum, long minNum){
    if(!root) return true;
    if(root->val <= minNum || root->val >= maxNum)
        return false;
    return isBST(root->left, root->val, minNum) && isBST(root->right, maxNum, root->val);
}

bool isValidBST(TreeNode* root) {
    return isBST(root, LONG_MAX, LONG_MIN);
}
};
