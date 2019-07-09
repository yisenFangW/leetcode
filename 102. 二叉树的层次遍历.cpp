给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

题解：
//这题开始想到的是树的层次遍历，即用一个队列将树中的元素进行存储，然后往外抛的时候，将他的左子节点与右子节点的值压入队列；
//1.但是要分层次，所以就是要存储上一次的状态，用一个vector<TreeNode *>tmp1存储状态；
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == nullptr)
        return res;
    vector<TreeNode*> vec;
    vec.push_back(root);
    res.push_back(vector<int>(1,root->val));
    while(!vec.empty()){
        //tmp1存本次状态，放入到vec中；tmp2存值；
        vector<int> tmp2;
        vector<TreeNode *> tmp1;
        for(int i=0;i<vec.size();++i) {
            if(vec[i]!= nullptr) {
                if (vec[i]->left) {
                    tmp1.push_back(vec[i]->left);
                    tmp2.push_back(vec[i]->left->val);
                }
                if (vec[i]->right) {
                    tmp1.push_back(vec[i]->right);
                    tmp2.push_back(vec[i]->right->val);
                }
            }
        }
        vec = tmp1;
        if(!tmp2.empty())
            res.push_back(tmp2);
    }
    return res;
}

//2.记录队列的上一次数值，然后进行顺序遍历，注意其中i的初值的赋予；
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    queue<TreeNode*>q{{root}};
    while(!q.empty()){
        vector<int> vec;
        //这个地方要用q.size()给i赋初值，因为q.size()是在不断变化的
        for(int i=q.size();i>0;--i){
            TreeNode* node = q.front();
            q.pop();
            vec.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
         }
        res.push_back(vec);
    }
    return res;
}
