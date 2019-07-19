给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

题解：
//这题拿到题，首先第一思路是遍历整个数，将数中的数字存入到unordered_map<int, int>中，然后再遍历map,找出map中最大的数量
//再遍历一次，将树中最大数量的数取出来；
void leftTravel(TreeNode* node, unordered_map<int, int>& m){
    if(!node) return;
    leftTravel(node->left, m);
    ++m[node->val];
    leftTravel(node->right, m);
}

vector<int> findMode(TreeNode* root) {
    if(!root) return {};
    unordered_map<int, int> m;
    vector<int> res;
    leftTravel(root, m);
    int maxLen = 0;
    for(auto iter = m.begin();iter!=m.end();++iter)
        maxLen = max(maxLen, iter->second);
    for(auto iter = m.begin();iter!=m.end();++iter) {
        if (iter->second == maxLen)
            res.push_back(iter->first);
    }
    return res;
}
