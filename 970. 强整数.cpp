给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。

返回值小于或等于 bound 的所有强整数组成的列表。

你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。

 

示例 1：

输入：x = 2, y = 3, bound = 10
输出：[2,3,4,5,7,9,10]
解释： 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
示例 2：

输入：x = 3, y = 5, bound = 15
输出：[2,4,6,8,10,14]
 

提示：

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6

题解：
//思路是先找出x和y的指数最大值，然后用两个for循环嵌套住里面的内容，用set去重，因为不要求顺序，直接将set
//的内容赋给vector返回值的内容就好啦。注意判断指数最大值的时候，有1的情况，会直接超时的。
class Solution {
public:
vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> s;
    int xx = 0, yy = 0;
    if(x == 1)
        xx = 1;
    else
        while (pow(x, xx) <= bound) ++xx;
    if(y == 1)
        yy = 1;
    else
        while (pow(y, yy) <= bound) ++yy;
    for (int i = 0; i < xx; ++i) {
        for (int j = 0; j < yy; ++j) {
            int sum = pow(x, i) + pow(y, j);
            if (sum <= bound)
                s.insert(sum);
        }
    }
    vector<int> res(s.begin(), s.end());
    return res;
}
};
