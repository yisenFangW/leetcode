515. 房屋染色
这里有n个房子在一列直线上，现在我们需要给房屋染色，分别有红色蓝色和绿色。每个房屋染不同的颜色费用也不同，
你需要设计一种染色方案使得相邻的房屋颜色不同，并且费用最小，返回最小的费用。

费用通过一个nx3 的矩阵给出，比如cost[0][0]表示房屋0染红色的费用，cost[1][2]表示房屋1染绿色的费用。

样例
样例 1:

输入: [[14,2,11],[11,14,5],[14,3,10]]
输出: 10
解释: 蓝 绿 蓝, 2 + 5 + 3 = 10
样例 2:

输入: [[1,2,3],[1,4,6]]
输出: 3
注意事项
所有费用都是正整数

题解：
//在这题学到的一个启示：若什么信息需要知道，但是不在传递函数中出现，就要将其记录下来（什么信息需要，就要将其记录下来）。
//(注意这种动态规划的方法，因为添加了颜色进去，所以需要将每一种颜色的最小值记录下来，因此用的是二维数组表示。)
//开始拿到这个题，想不到传递函数的写法，因为需要记录颜色的数据，经过指点，确定一个二维数组，行数为房子的数量，列数为颜色数，即为3
//每种传递函数，例如dp[i][0] = min(dp[i - 1][1] + costs[i - 1][0], dp[i - 1][2] + costs[i - 1][0]);
//第i间房子涂第0中颜色，则最小值为，第i-1间房子涂第1中颜色加上第i间涂第0中颜色的费用与第i-1间房子涂第2种颜色加上第i间涂第0中颜色的费用
//最后判断最后一件房子涂颜色的最小值，即是最小值
int minCost(vector<vector<int>> &costs) {
	if (costs.empty() || costs[0].empty())
		return 0;
	int size = costs.size();
	vector<vector<int>> dp(size + 1, vector<int>(3, 0));
	for (int i = 0; i < 3; ++i) dp[0][i] = 0;
	for (int i = 1; i <= size; ++i) {
		dp[i][0] = min(dp[i - 1][1] + costs[i - 1][0], dp[i - 1][2] + costs[i - 1][0]);
		dp[i][1] = min(dp[i - 1][0] + costs[i - 1][1], dp[i - 1][2] + costs[i - 1][1]);
		dp[i][2] = min(dp[i - 1][0] + costs[i - 1][2], dp[i - 1][1] + costs[i - 1][2]);
	}
	return min(dp[size][0], min(dp[size][1], dp[size][2]));
}
