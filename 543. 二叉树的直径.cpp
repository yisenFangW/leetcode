给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

题解：
//1.这题就是看两个左右子树的深度，然后结果就是最大的左右子树的深度相加：
int depth(TreeNode* root, int num){
    if(!root)
        return num;
    return max(depth(root->left, num+1), depth(root->right, num+1));
}

void Travel(TreeNode* root, vector<TreeNode*>& vec){
    if(root){
        vec.push_back(root);
        Travel(root->left, vec);
        Travel(root->right, vec);
    }
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    vector<TreeNode*> roots;
    Travel(root, roots);
    int maxLen = 0;
    for(auto root:roots){
        int num = depth(root->left, 0)+ depth(root->right, 0) - 1;
        maxLen = max(maxLen, num);
    }
    return maxLen;
}

//2.看别人的写法，用一个unordered_map存之前遍历过的树的子树深度
class Solution {
public:
int depth(TreeNode* root){
    if(!root)
        return 0;
    if(umap.count(root)) return umap[root];
    int len = 1+ max(depth(root->left),depth(root->right));
    umap[root] = len;
    return len;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int len = depth(root->left)+depth(root->right);
    return max(len, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}
private:
    unordered_map<TreeNode* , int> umap;
};
