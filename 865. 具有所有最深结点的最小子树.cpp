给定一个根为 root 的二叉树，每个结点的深度是它到根的最短距离。

如果一个结点在整个树的任意结点之间具有最大的深度，则该结点是最深的。

一个结点的子树是该结点加上它的所有后代的集合。

返回能满足“以该结点为根的子树中包含所有最深的结点”这一条件的具有最大深度的结点。


示例：

输入：[3,5,1,6,2,0,8,null,null,7,4]
输出：[2,7,4]
解释：

我们返回值为 2 的结点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的结点。
输入 "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" 是对给定的树的序列化表述。
输出 "[2, 7, 4]" 是对根结点的值为 2 的子树的序列化表述。
输入和输出都具有 TreeNode 类型。
 

提示：

树中结点的数量介于 1 和 500 之间。
每个结点的值都是独一无二的。

题解：
//一个树的最大深度节点，这个例子中给出的是7和4，所以往上遍历一个，找到公共父节点2，但是如果像是完全二叉树那种，底下所有的左右子树
//都是同样的深度，就应该好似返回根节点。
//先找出左子树和右子树的深度，然后若左右子树深度相同，则返回跟节点，若左子树的深度大于右子树，则递归遍历左子树，然后依次往下写
//很巧妙啊，代码也很精简；
class Solution {
public:  
//这题比较难，有点难理解，注意多看看；
int depth(TreeNode* node){
    return !node?0:(max(depth(node->left), depth(node->right))+1);
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    //if(!root) return nullptr;
    int diff = depth(root->left) - depth(root->right);
    return (diff == 0)?root:subtreeWithAllDeepest(diff>0?root->left:root->right);
}
};
