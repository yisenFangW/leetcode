给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]


题解：
//1.看到这题，首先想到的是在层序遍历的时候加判断，然后很快写出代码，但是这个代码是错误的，因为不适合所有的情况
//当[1,2,3,4,null,null,5]时，就不能正确的按顺序输出了，因为这个是根据存入栈中的子树，然后遍历左右或者由左子树
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return{};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    bool flag = false;
    while(!q.empty()){
        int n = q.size();
        vector<int> vec;
        for(int i=0;i<n;++i){
            TreeNode* tmp = q.front();
            q.pop();
            if(flag){
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }else{
                if(tmp->right)
                    q.push(tmp->right);
                if(tmp->left)
                    q.push(tmp->left);
            }
            vec.push_back(tmp->val);
        }
        flag = !flag;
        res.push_back(vec);
    }
    return res;
}

//2.第二种方法是将层序遍历的res中，每一个需要颠倒位置的vec换个位置就OK啊，这样比较方便想，实现起来也比较简单；
//看一个博主用的两个栈来存，然后实现，方法也没见得省了多少事，就没用那样实现一遍了；
void swapVec(vector<int> &vec){
    if(vec.size() <= 1)
        return;
    for(int i=0,j=vec.size()-1;i<=j;)
        swap(vec[i++], vec[j--]);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return{};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    while(!q.empty()){
        int n = q.size();
        vector<int> vec;
        for(int i=0;i<n;++i){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            vec.push_back(tmp->val);
        }
        res.push_back(vec);
    }
    for(int i=0;i<res.size();++i) {
        if((i+1)%2 == 0)
            swapVec(res[i]);
    }
    return res;
}




