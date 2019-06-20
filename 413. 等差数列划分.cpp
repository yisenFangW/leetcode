如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
以下数列不是等差数列。

1, 1, 2, 5, 7
 

数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。

如果满足以下条件，则称子数组(P, Q)为等差数组：

元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。

函数要返回数组 A 中所有为等差数组的子数组个数。

 

示例:

A = [1, 2, 3, 4]

返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。

题解：
//1.长度为n的等差数列有1个，长度为n-1的等差数列有2个，... ，长度为3的等差数列有 n-2 个，那么总共就是 1 + 2 + 3 + ... + n-2 ，
//根据规律，等差数组的个数为(n-1)(n-2)/2个
int numberOfArithmeticSlices(vector<int>& A) {
	if (A.size() < 3)
		return 0;
	vector<int> dp(A.size(), 0);
	int res = 0;
	for (int i = 2; i < A.size(); ++i) {
		if (A[i] - A[i - 1] != A[i - 1] - A[i - 2]) {
			if (dp[i - 1])
				res += ((dp[i - 1] - 1)*(dp[i - 1] - 2) / 2);
		}
		else {
			if (dp[i - 1] == 0)
				dp[i] = dp[i - 1] + 3;
			else
				dp[i] = dp[i - 1] + 1;
		}
	}
	if (dp[A.size() - 1])
		res += ((dp[A.size() - 1] - 1)*(dp[A.size() - 1] - 2) / 2);
	return res;
}

//2.等差数组的个数res += dp[i];
int numberOfArithmeticSlices(vector<int>& A) {
	if (A.size() < 3)
		return 0;
	vector<int> dp(A.size(), 0);
	int res = 0;
	for (int i = 2; i < A.size(); ++i) {
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
			dp[i] = dp[i - 1] + 1;
		res += dp[i];
	}
	return res;
}
