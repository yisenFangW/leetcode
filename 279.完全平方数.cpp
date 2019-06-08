给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

解题：
//拿到题目第一反应，动态规划，硬币找零的变种问题，很快解题成功
int numSquares(int n) {
	vector<int> vec(n+1, 1);
	vec[1] = 1; vec[0] = 0;
	for (int i = 2; i <= n; i++) {
		int tmp = int(sqrt(i));
    //INT_MAX头文件为#include<climits>
		int minNum = INT_MAX;
		for (int j = 1; j <= tmp; ++j)
			minNum = min(vec[j*j] + vec[i - j * j], minNum);
		vec[i] = minNum;
	}
	return vec[n];
}
