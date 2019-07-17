实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。

 

示例：



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false

题解：
//拿到题目一看是二叉搜索树，则中序遍历是有序的，然后将数据存入到vector<int>容器中，设置一个下标值，依次往后遍历
class BSTIterator {
public:
    vector<int> vec;
    int index = 0;
    void inTravel(TreeNode* root){
        if(root!=nullptr){
            inTravel(root->left);
            vec.push(root->val);
            inTravel(root->right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        inTravel(root);
        
    }
    
    /** @return the next smallest number */
    int next() {
        return vec[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index < vec.size())
            return true;
        return false;
    }
};
