在本问题中, 树指的是一个连通且无环的无向图。

输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。

返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

示例 1：

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3
示例 2：

输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
解释: 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3
注意:

输入的二维数组大小在 3 到 1000。
二维数组中的整数在1到N之间，其中N是输入数组的大小。

题解：
这题开始不知道用并查集解题，思路是找一个节点出现超过三次的节点数量，然后再找最后一个，那种思路不对，导致解题都出现问题了，不知道该怎么解，
这题其实很简单，就是找到最后一个使之前的集合成环的节点，即明显的并查集解题：

int findRoot(int i, const vector<int> &vec) {
    while (vec[i] != -1)
        i = vec[i];
    return i;
}

// 因为这里需要对vec进行修改，因此传入的必须要是引用
bool unionRoot(int x, int y, vector<int> &vec) {
    int x_root = findRoot(x, vec);
    int y_root = findRoot(y, vec);
    if (x_root == y_root)
        return false;
    else {
        vec[x_root] = y_root;
        return true;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int size = edges.size();
    vector<int> vec(size + 1, -1);
    for (int i = 0; i < size; ++i) {
        if (!unionRoot(edges[i][0], edges[i][1], vec)) {
            return edges[i];
        }
    }
    return edges[edges.size() - 1];
}
