给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

 

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

输出：[7,4,1]

解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1



注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
 

提示：

给定的树是非空的，且最多有 K 个结点。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.

题解：
//树的题目，这题比较难搞，主要就是要找到祖先节点的内容，所以首先需要用一个unordered_map<TreeNode*, TreeNode*>将树的所有节点
//祖先节点存起来，用unordered_set<TreeNode*>存走过的路径，最后返回长度为K的节点值；
void parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m){
   //用unordered_map<TreeNode*, TreeNode*>& m存所有节点的父节点；
   if(!root) return;
   if(root->left) m[root->left] = root;
   if(root->right) m[root->right] = root;
   parents(root->left, m);
   parents(root->right, m);
}

void helper(TreeNode* root, int K, unordered_map<TreeNode*, TreeNode*>& m,
        unordered_set<TreeNode*>& s, vector<int>& res){
    //用unordered_set存走过的路，不然因为有父节点，然后又往回走了，就不对了；
    if(s.count(root) || K < 0) return;
    s.insert(root);
    if(K == 0) {
        res.push_back(root->val);
        return;
    }
    //这个地方要注意判断所要的节点是否是空节点；
    if(root->left) helper(root->left, K-1, m, s, res);
    if(root->right) helper(root->right, K-1, m, s, res);
    if(m[root]) helper(m[root], K-1, m ,s, res);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    if(!root) return {};
    unordered_set<TreeNode*> s;
    unordered_map<TreeNode*, TreeNode*> m;
    vector<int> res;
    parents(root, m);
    helper(target, K, m, s, res);
    return res;
}
