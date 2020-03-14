给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。

添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。

将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。

如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

示例 1:

输入: 
二叉树如下所示:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

输出: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

示例 2:

输入: 
二叉树如下所示:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

输出: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
注意:

输入的深度值 d 的范围是：[1，二叉树最大深度 + 1]。
输入的二叉树至少有一个节点。

题解：
这题首先想到的是树的层序遍历，遍历到要添加元素的那一行，在queue中留下那一行的元素，添加上新增的元素即可：
TreeNode *addOneRow(TreeNode *root, int v, int d) {
    if (d == 1) {
        auto *node = new TreeNode(v);
        node->left = root;
        return node;
    }
    queue<TreeNode *> q;
    auto res = root;
    q.push(res);
    for (int i = 0; i < d - 2; ++i) {
        while (!q.empty()) {
            int n = q.size();
            for (int k = 0; k < n; ++k) {
                auto *tmp = q.front();
                q.push(tmp->left);
                q.push(tmp->right);
                q.pop();
            }
        }
    }
    while (!q.empty()) {
        auto *node = q.front();
        auto *leftNode = new TreeNode(v);
        leftNode->left = node->left;
        auto *rightNode = new TreeNode(v);
        rightNode->right = node->right;
        node->left = leftNode;
        node->right = rightNode;
        q.pop();
    }
    return root;
}

第二种方法是借鉴网上别人写的内容，利用d==0或d==1判断左子树还是右子树，进行递归求解，树的题目都是可以递归实现的；
TreeNode *addOneRow(TreeNode *root, int v, int d) {
    if (d == 0 || d == 1) {
        auto* node = new TreeNode(v);
        d ? node->left : node->right = root;
        return node;
    }
    if (root && d > 1) {
        root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
        root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
    }
    return root;
}
