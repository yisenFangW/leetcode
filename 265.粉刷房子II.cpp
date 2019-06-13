描述
中文
English
这里有n个房子在一列直线上，现在我们需要给房屋染色，共有k种颜色。每个房屋染不同的颜色费用也不同，你需要设计一种染色方案使得相邻的房屋颜色不同，并且费用最小。

费用通过一个nxk 的矩阵给出，比如cost[0][0]表示房屋0染颜色0的费用，cost[1][2]表示房屋1染颜色2的费用。
所有费用都是正整数

样例
样例1

输入:
costs = [[14,2,11],[11,14,5],[14,3,10]]
输出: 10
说明:
三个屋子分别使用第1,2,1种颜色，总花费是10。
样例2

输入:
costs = [[5]]
输出: 5
说明：
只有一种颜色，一个房子，花费为5
挑战
用O(nk)的时间复杂度解决

题解：
//1.第一想法肯定是动态规划，这题是由粉刷房子延伸而来，粉刷房子是由三种颜色组成，这个有k中颜色构成，常规解法，时间复杂度O(n*k*k)
//通过率94%,这样写，每次都要判断一遍大小，paintNum做了两次循环
vector<int> countBits(int num) {
	if (num == 0)
		return vector<int>(1, 0);
	vector<int> dp(num + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= num; ++i)
		dp[i] = dp[i >> 1] + i % 2;
	return dp;
}

int minCostII(vector<vector<int>> &costs) {
	if (costs.empty() || costs[0].empty())
		return 0;
	int houseNum = costs.size();
	int paintNum = costs[0].size();
	vector<vector<int>> dp(houseNum + 1, vector<int>(paintNum, INT_MAX));
	for (int j = 0; j < paintNum; ++j)
		dp[0][j] = 0;
	for (int i = 1; i <= houseNum; ++i) {
		for (int j = 0; j < paintNum; ++j) {
			for (int k = 0; k < paintNum; ++k) {
				if (k != j)
					dp[i][j] = min(dp[i][j], dp[i - 1][k]);
			}
			if (dp[i][j] == INT_MAX)
				dp[i][j] = 0;
			dp[i][j] += costs[i-1][j];
		}
	}
	cout << dp[1][0] << endl;
	int minCosts = INT_MAX;
	for (int i = 0; i < paintNum; ++i)
		minCosts = min(minCosts, dp[houseNum][i]);
	return minCosts;
}

//2.改进版，改进版记录了最小值和次小值，以及最小值min1和次小值min2的j(min1j, min2j)值，再次进行循环，若j==min1j,则最小值为min2
//否则都为min1;时间复杂度O(n*k)
int minCostII(vector<vector<int>> &costs) {
	if (costs.empty() || costs[0].empty())
		return 0;
	int houseNum = costs.size();
	int paintNum = costs[0].size();
	vector<vector<int>> dp(houseNum + 1, vector<int>(paintNum, INT_MAX));
	for (int j = 0; j < paintNum; ++j)
		dp[0][j] = 0;
	for (int i = 1; i <= houseNum; ++i) {
		int min1 = INT_MAX, min2 = INT_MAX;
		int min1j = 0, min2j = 0;
		for (int j = 0; j < paintNum; ++j) {
			if (dp[i - 1][j] <= min1) {
				min2 = min1;
				min2j = min1j;
				min1 = dp[i - 1][j];
				min1j = j;
			}
			else if (dp[i - 1][j] < min2) {
				min2 = dp[i - 1][j];
				min2j = j;
			}
		}
		if (min2 == INT_MAX) 
			min2 = 0;
		for (int j = 0; j < paintNum; ++j) {
			if (j != min1j)
				dp[i][j] = min1 + costs[i - 1][j];
			else
				dp[i][j] = min2 + costs[i - 1][j];
		}
	}
	int minCosts = INT_MAX;
	for (int i = 0; i < paintNum; ++i)
		minCosts = min(minCosts, dp[houseNum][i]);
	return minCosts;
}






