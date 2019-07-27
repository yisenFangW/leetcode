给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

示例 1：
输入：[1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
示例 2：

输入：[1,2,3,4,5,null,7]
输出：false
解释：值为 7 的结点没有尽可能靠向左侧。
 
提示：
树中将会有 1 到 100 个结点。

题解：
//这题开始拿到并没有什么思路，看了一些别人的题解，说用一个flag作为标志，标志这如果中间缺一个数，就将flag置为1，然后根据flag与树
//的结构开始做判断，判断结果是否正确；
bool isCompleteTree(TreeNode* root) {
    if(!root) return true;
    queue<TreeNode*> q;
    bool flag = false;
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(flag && (node->left || node->right)) return false;
        if(node->left) q.push(node->left);
        else flag = true;
        if(flag && !node->right) return false;
        if(node->right) q.push(node->right);
        else flag = true;
    }
    return true;
}
