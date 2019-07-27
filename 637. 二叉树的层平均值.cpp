给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

示例 1:

输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：

节点值的范围在32位有符号整数范围内。

题解：树的层序遍历，没啥好说的，下次遇到这种题不做啦，没有什么营养；
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<double> res;
    while(!q.empty()){
        int n = q.size();
        double sum = 0;
        for(int i=0;i<n;++i){
            TreeNode* tmp = q.front();
            q.pop();
            sum += tmp->val;
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        res.push_back(sum/n);
    }
    return res;
}
};
