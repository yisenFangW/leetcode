给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

题解：
//1.自己的想法，就是顺序遍历树？然后记录下每层的这样，又他妈变成了树的遍历，我发现树的所有问题，都可以用遍历解决，这样的话，就是空间复杂度会比较高
//方法不好。
int countNodes(TreeNode* root) {
    if(!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while(!q.empty()){
        int num = q.size();
        res+=num;
        for(int i=0;i<num;++i){
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return res;
}

//2.看了一下别人的题解，别人就利用了完全二叉树的性质，找到最左的那个节点，记录下层数，找到最右的那个节点，记录下层数，
//若层数相同，说明这颗树是完美二叉树，直接返回pow(2, 层数h) - 1，要是不是，就进行左子树和右子树的递归运算，注意要加上根节点，即+1；
class Solution {
public:
    int countNodes(TreeNode* root){
        if(!root) return 0;
        TreeNode* left = root, * right = root;
        int leftCount = 0, rightCount = 0;
        while(left){
            ++leftCount;
            left = left->left;
        }
        while(right){
            ++rightCount;
            right = right->right;
        }
        if(leftCount == rightCount)
            return pow(2, leftCount) - 1;
        return countNodes(root->left) + countNodes(root->right)+1;
    }
};




