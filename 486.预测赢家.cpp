给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

示例 1:

输入: [1, 5, 2]
输出: False
解释: 一开始，玩家1可以从1和2中进行选择。
如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
因此，玩家1永远不会成为赢家，返回 False。
示例 2:

输入: [1, 5, 233, 7]
输出: True
解释: 玩家1一开始选择1。然后玩家2必须从5和7中进行选择。无论玩家2选择了哪个，玩家1都可以选择233。
最终，玩家1（234分）比玩家2（12分）获得更多的分数，所以返回 True，表示玩家1可以成为赢家。
注意:

1 <= 给定的数组长度 <= 20.
数组里所有分数都为非负数且不会大于10000000。
如果最终两个玩家的分数相等，那么玩家1仍为赢家。

解题：
//1.这题拿到首先想到的是贪心算法，想每次都拿最大的，但是好像不行，有些情况明显不适用，比如{1,5,233,7}这个测试用例，对于这种情况
//若贪心算，则会先拿7，但是拿7的话，233就会被后手拿了
//自己想动态规划，但是想不太到，就看别人的题解写的dp[i][j]表示在i~j范围内能拿到的最优解
//当i==j时，dp[i][j] = nums[i];首先给这个初始值赋值，然后再继续进行计算
//当i!=j时，若先手取左端nums[i]，后手则为dp[i+1][j],若先手取右端nums[j]，后手则为dp[i][j-1]，dp[i][j] = max(nums[i]-dp[i-1][j], nums[j]-dp[i][j-1]);
//注意下面两个for循环的顺序，必须要有顺序才能够完成
bool PredictTheWinner(vector<int>& nums) {
	int n = nums.size();
	//dp[i][j]代表在i,j范围内，先手比后手拿到最好的多多少。
	vector<vector<int>> dp(n, vector<int>(n, 0));
	//当i==j时，取得的在i-j范围内，最大值即为nums[i]；
	//注意这个下面的初始化顺序，若测试用例为{1,5,2}；
	//是从dp[0][1],dp[1][2],然后顺序是dp[0][2]；
	for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
	for (int len = 1; len < n; ++len) {
		for (int i = 0, j = len; j < n; ++i, ++j) {
			//当先手拿num[i](左侧),后手拿的最好值为dp[i+1][j]
			//当先手拿num[j](右侧),后手拿的最好值为dp[i][j-1]
			dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	//返回dp[0][n-1],以为开始第一次拿是0，最后一次拿是n-1,代表在0~n-1范围内先手是否能比后手多
	return dp[0][n-1] >= 0;
}
