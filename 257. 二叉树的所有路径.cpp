给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

题解：
//开始写有问题，是因为传入的string也为引用，然后就导致结果为1->2->5, 1->2->3,就是每次pop不干净，为啥我要将中间的string也设为引用？？
//傻了傻了，这题只需要将vector<string> res设为引用即可，思路是对的，即遍历整个树；
void binary(TreeNode* root, string str, vector<string>& res){
    if(!root) return;
    if(str.empty())
        str += to_string(root->val);
    else
        str = str + "->" + to_string(root->val);
    if(!root->left && !root->right) {
        res.push_back(str);
        str.pop_back();
    }
    binary(root->left, str, res);
    binary(root->right, str, res);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(!root)
        return res;
    string str = "";
    binary(root, str, res);
    return res;
}
