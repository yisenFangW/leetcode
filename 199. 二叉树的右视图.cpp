给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

题解：
//题目就是二叉树层序遍历的一个变形而已，就是取二叉树的每一层的最右边一个数字，用一个队列进行存，然后一层一层取，取每层最后一个；
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;++i){
                if(i == n-1) {
                    res.push_back(q.front()->val);
                }
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();

            }
        }
        return res;
    }
};
