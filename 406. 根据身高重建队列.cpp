假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

题解：
//这题想了蛮久才想出来解题方法，先将每个vector排序，然后按首元素从大到小排，再按第二个元素从小往大排，然后依次往一个新的数组中插入即可；
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]) return v1[1]<v2[1];
        else return v1[0]>v2[0];
        });
    vector<vector<int>> res;
    for(auto p:people)
        res.insert(res.begin()+p[1], p);
    return res;
}
