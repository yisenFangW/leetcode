给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


题解：由题意可知，对图中对二叉树采用的是前序遍历，然后将其转换为链表
//1.自己的思路，将前序遍历得到的各个元素的左子树赋为空，然后右子树接上下一个元素；
void preTravel(TreeNode* root, vector<TreeNode*>& vec){
    if(root){
        vec.push_back(root);
        preTravel(root->left, vec);
        preTravel(root->right, vec);
    }
}

void flatten(TreeNode* root) {
    vector<TreeNode*> vec;
    //TreeNode* node = root;
    preTravel(root, vec);
    for(int i=0;i<vec.size();++i){
        vec[i]->left = nullptr;
        if(i+1<vec.size())
            vec[i]->right = vec[i+1];
    }
}

//2.看的别人的思路，递归解法：找到最左边的一个，然后将左子树放到右子树上，右子树本来的元素，接在左子树的最右边元素上
//然后顺序遍历结果
void flatten(TreeNode* root) {
    if(!root) return;
    if(root->left) flatten(root->left);
    if(root->right) flatten(root->right);
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while(root->right) root = root->right;
    root->right = tmp;
}

//3.非递归解法，直接是遇到左子树存在，就将左子树放到右子树，右子树找到原左子树的最右边一个元素，接上；
void flatten(TreeNode* root) {
    if(!root) return;
    while(root){
        if(root->left) {
            TreeNode *tmp = root->right;
            TreeNode *node = root;
            root->right = root->left;
            root->left = nullptr;
            while (node->right) node = node->right;
            node->right = tmp;
        }
        root = root->right;
    }
}





