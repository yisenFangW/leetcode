你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 

提示：

输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
1 <= numCourses <= 10^5

//这道题开始拿到题目，不知道该怎么下手，看了题解之后才知道需要判断有向图中是否存在环；
//用一个vector<vector<int>>存放图的建立；
//用一个vector<int> in存放图的度；
//把度为0的都放到queue中，减去对应的度，最后判断；
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if(2*prerequisites.size() < numCourses)
        return false;
    vector<vector<int>> vec(numCourses);
    vector<int> in(numCourses, 0);
    for (auto prerequisite : prerequisites) {
        vec[prerequisite[1]].push_back(prerequisite[0]);
        ++in[prerequisite[0]];
    }
    queue<int> q;
    for (int i = 0; i< numCourses; ++i) {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto i:vec[t]) {
            --in[i];
            if (in[i] == 0)
                q.push(i);
        }
    }
    for(int i = 0;i<numCourses;++i){
        if(in[i] != 0)
            return false;
    }
    return true;
}




