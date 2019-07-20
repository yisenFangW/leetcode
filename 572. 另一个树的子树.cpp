给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。

题解：(简单题还花了漫长时间的，不应该)
//这题开始写的时候，准备用一个函数递归，然后总是会有一些情况考虑不周全，然后
//将函数的递归拆分成两个函数，就OK了
bool isSame(TreeNode* s, TreeNode* t){
    if(!s && !t) return true;
    if(!s || !t) return false;
    if(s->val != t->val) return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if(!s) return false;
    if(isSame(s,t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}










