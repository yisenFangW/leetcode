描述
中文
English
给定 n 本书, 第 i 本书的页数为 pages[i]. 现在有 k 个人来复印这些书籍, 而每个人只能复印编号连续的一段的书, 比如一个人可以复印 pages[0], pages[1], pages[2], 但是不可以只复印 pages[0], pages[2], pages[3] 而不复印 pages[1].

所有人复印的速度是一样的, 复印一页需要花费一分钟, 并且所有人同时开始复印. 怎样分配这 k 个人的任务, 使得这 n 本书能够被尽快复印完?

返回完成复印任务最少需要的分钟数.

样例
样例 1:

输入: pages = [3, 2, 4], k = 2
输出: 5
解释: 第一个人复印前两本书, 耗时 5 分钟. 第二个人复印第三本书, 耗时 4 分钟.
样例 2:

输入: pages = [3, 2, 4], k = 3
输出: 4
解释: 三个人各复印一本书.
挑战
时间复杂度 O(nk)

题解：本题为LintCode上困难题，在看视频时候看到的，因此就做了一下
//这题的难点就难在不知道如何找递推公式,dp[k][i] = min(dp[k][i], max(dp[k-1][j], sum)); sum为pages[j]+...+pages[i-1];
//其中k为复印人的数量，i为第i本书的复印量。

int copyBooks(vector<int> &pages, int K) {
	if (pages.empty() || K <= 0)
		return 0;
	int n = pages.size();
	int maxPage = 0;
	if (K >= n) {
		for (auto page : pages)
			maxPage = max(maxPage, page);
		return maxPage;
	}
	vector<vector<int>> dp(K + 1, vector<int>(n + 1, 0));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)  dp[0][i] = INT_MAX;
	int sum = 0;
	for (int k = 1; k <= K; ++k) {
		dp[k][0] = 0;
		for (int i = 0; i <= n; ++i) {
			dp[k][i] = INT_MAX;
			sum = 0;
      //因为sum为pages[j]到pages[i-1]的和，所以倒着写会方便一些
			for (int j = i; j >= 0; --j) {
				dp[k][i] = min(dp[k][i], max(dp[k - 1][j], sum));
				if (j > 0)
					sum += pages[j - 1];
			}
		}
	}
	return dp[K][n];
}
