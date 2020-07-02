给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :


返回其后序遍历: [5,6,3,2,4,1].
说明: 递归法很简单，你可以使用迭代法完成此题吗?

//题目说的递归法很简单，但是递归法首先还是没有想到，还是菜的啊；
1.递归：
void help(Node* root, vector<int>& res){
    if(!root) return;
    vector<int> vec;
    for(auto node: root->children)
        help(node, res);
    res.push_back(root->val);
}

vector<int> postorder(Node *root) {
    vector<int> res;
    help(root, res);
    return res;
}

2.非递归是自己写的：
vector<int> postorder(Node *root) {
    if(!root) return vector<int>();
    stack<Node*> s1;
    stack<int> s2;
    s1.push(root);
    while(!s1.empty()){
        Node* tmp = s1.top();
        s1.pop();
        s2.push(tmp->val);
        for(int i = 0; i<tmp->children.size(); ++i){
            s1.push(tmp->children[i]);
        }
    }
    vector<int> res;
    while(!s2.empty()){
        res.push_back(s2.top());
        s2.pop();
    }
    return res;
}
