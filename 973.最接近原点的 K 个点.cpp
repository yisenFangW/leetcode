我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
 

提示：

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

题解：
这题的第1思路是用堆排序去解，写习惯了大根堆，用的还是大根堆实现的，看了评论很多用C++默认的排序和优先级队列，但是我写的比较啰嗦，
还是自己实现的一个堆排序过程，涉及到多个拷贝过程，用的内存还是偏大；
堆排序的时候，用pair<int, long>，first记录在原points中的位置，second代表计算出来的点离圆心的距离，用距离来排序

void buildMaxPairHeap(int i, int n, vector<pair<int, long>> &vec) {
    int left = 2 * i + 1, right = 2 * i + 2, max = i;
    if (left < n && vec[left].second > vec[max].second) max = left;
    if (right < n && vec[right].second > vec[max].second) max = right;
    if (max != i) {
        swap(vec[max], vec[i]);
        buildMaxPairHeap(max, n, vec);
    }
}

void maxPairHeap(vector<pair<int, long>> &vec, int k) {
    for (int i = vec.size() / 2 - 1; i >= 0; --i)
        buildMaxPairHeap(i, vec.size(), vec);
    for (int i = vec.size() - 1; i >= k; --i) {
        swap(vec[i], vec[0]);
        buildMaxPairHeap(0, i, vec);
    }
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    vector<pair<int, long>> len;
    for (int i = 0; i < points.size(); ++i)
        len.push_back(pair<int, long>(i, sqrt(points[i][0]) + sqrt(points[i][1])));
    maxPairHeap(len, K);
    vector<vector<int>> res;
    for (int i = 0; i < K; ++i) {
        res.push_back(points[len[i].first]);
    }
    return res;
}

