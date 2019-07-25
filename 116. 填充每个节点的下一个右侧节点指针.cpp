给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

示例：

输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

题解：
//1.首先想到的是层序遍历，然后只有每层的最后一个是指向nullptr的，然后其他的都是指向队列下一个；
Node* connect(Node* root) {
    if(!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;++i){
            Node* tmp = q.front();
            q.pop();
            if(i == n-1)
                tmp->next = nullptr;
            else
                tmp->next = q.front();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }
    return root;
}

//2.递归解法，因为是完美二叉树，所以有左子树一定有右子树，右子树是不是最靠右边的需要看根节点的next是否存在，若存在则指向跟节点next的左子树，
//若不存在说明是最右边一个是最靠右边的；
Node* connect(Node* root) {
    if(!root) return nullptr;
    if(root->left) root->left->next = root->right;
    if(root->right) root->right->next = (root->next)?root->next->left: nullptr;
    connect(root->left);
    connect(root->right);
    return root;
}
