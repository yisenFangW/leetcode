给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

Example 1:

输入: [3,2,1,6,0,5]
输入: 返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
注意:

给定的数组的大小在 [1, 1000] 之间。

题解：
//1.很明显就是一题树的递归求解问题，先找出最大值，再将最大值左边的数构造左子树，右边的数构造右子树，然后递归就可以求的最后的结果；
//很能代表树的递归的一道题
TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right){
    if(left>right)
        return nullptr;
    if(left == right)
        return new TreeNode(nums[left]);
    int maxNum = nums[left], index = left;
    for(int i=left;i<=right;++i){
        if(nums[i]>maxNum){
            maxNum = nums[i];
            index = i;
        }
    }
    TreeNode* root = new TreeNode(maxNum);
    root->left = constructMaximumBinaryTree(nums, left, index-1);
    root->right = constructMaximumBinaryTree(nums, index+1, right);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size()-1);
}
