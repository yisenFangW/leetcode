给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。

题解：
这题开始找不到思路，看了别人的题解有的思路，将数序列化，并存在unordered_map中，如果超过1，就说明之前已经存进去过，即重复
string listTree(TreeNode *root, vector<TreeNode *> &vec, unordered_map<string, int> &m) {
    if (!root) return "#";
    string res = to_string(root->val) + "," + listTree(root->left, vec, m) + "," + listTree(root->right, vec, m);
    if (m[res] == 1) vec.push_back(root);
    ++m[res];
    return res;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode *> vec;
    unordered_map<string, int> m;
    listTree(root, vec, m);
    return vec;
}
