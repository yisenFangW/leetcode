给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入: 
    1
   / \
  0   2

  L = 1
  R = 2

输出: 
    1
      \
       2
示例 2:

输入: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出: 
      3
     / 
   2   
  /
 1

题解：
//1.首先拿到题目的第一思路是通过中序遍历将所有的满足大小的节点存进去，然后再将开头和结尾的左子树和右子树赋0，然后将所有的子树连接起来
//这样做会改变数的结构，源代码如图，这是错误的示范，解的有问题；

//错误解法
void leftTravel(TreeNode* root, vector<TreeNode*>& vec, int L, int R){
    if(root){
        leftTravel(root->left, vec, L, R);
        if((root->val >= L) && (root->val <= R))
            vec.push_back(root);
        leftTravel(root->right, vec, L, R);
    }
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
    if(!root) return nullptr;
    vector<TreeNode*> vec;
    leftTravel(root, vec, L, R);
    if(vec.empty()) return nullptr;
    vec.front()->left = nullptr;
    vec.back()->right = nullptr;
    int index = -1;
    for(int i=0;i<vec.size()-1;++i){
        vec[i]->right = vec[i+1];
        vec[i+1]->left = vec[i];
        if(vec[i] == root)
            index = i;
        if(vec[i+1] == root)
            index = i+1;
    }
    return index == -1?vec.front():vec[index];
}
//2.正确的解法，对树进行递归，如果节点为空，返回nullptr,如果节点小于L，则返回节点的右子树的值，如果节点大于R，返回节点的左子树的值
//如果在[L,R]之间，将左子树的值，返回左子树，右子树的值，返回右子树；最后返回root；
TreeNode* trimBST(TreeNode* root, int L, int R) {
    if(!root) return nullptr;
    if(root->val < L) return trimBST(root->right, L, R);
    if(root->val > R) return trimBST(root->left, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}


