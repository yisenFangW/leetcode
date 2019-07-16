您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]

题解：
//这题开始自己写，空间复杂度很高，因为没有记录每一行的数据，所以用vector<vector<TreeNode*>>记录，这种方法比较笨；
vector<int> largestValues(TreeNode* root) {
    if(!root) return {};
    vector<vector<TreeNode*>> vec;
    vec.push_back({root});
    while(1){
        vector<TreeNode*> tmp;
        vector<TreeNode*> end = vec.back();
        for(auto tree:end){
            if(!tree)
                continue;
            if(tree->left)
                tmp.push_back(tree->left);
            if(tree->right)
                tmp.push_back(tree->right);
        }
        if(tmp.empty())
            break;
        vec.push_back(tmp);
    }
    vector<int> res;
    for(auto arr:vec){
        int max = INT_MIN;
        for(auto tree:arr) {
            if(!tree) continue;
            if (tree->val > max)
                max = tree->val;
        }
        res.push_back(max);
    }
    return res;
}

//2常规的用队列来进行层次遍历的方法；需要记录每行多少个节点，然后用for循环做每个节点的循环模式；
vector<int> largestValues(TreeNode* root){
    if(!root) return{};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int n = q.size();
        int maxNum = INT_MIN;
        for(int i=0;i<n;++i){
            TreeNode* node = q.front();
            q.pop();
            maxNum = max(maxNum, node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        res.push_back(maxNum);
    }
    return res;
}

