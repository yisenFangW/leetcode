给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
进阶:

给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

题解：
//1.O(nlogn)解答，每个数都带入求二进制中1个数的方程中计算
//func(int num)函数为求解二进制中1的个数的函数
int func(int num) {
	int cnt = 0;
	while (num) {
		++cnt;
		num = num & (num - 1);
	}
	return cnt;
}

vector<int> countBits(int num) {
	vector<int> res;
	for (int i = 0; i <= num; ++i)
		res.push_back(func(i));
	return res;
}	

//2.动态规划O(n),本题动态规划的重点是递归方程是如何写的，如5的2进制写法，1001，去掉最后一位为100，即为4，判断最后一位是否为1，要是1
//则加上，若是0，则不加
vector<int> countBits(int num) {
	if (num == 0)
		return vector<int>(1, 0);
	vector<int> dp(num + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= num; ++i)
		dp[i] = dp[i >> 1] + i % 2;
	return dp;
}

//3.动态规划，另一种思想，是从第一种方法，func()函数演变过来的，
vector<int> countBits(int num) {
	if (num == 0)
		return vector<int>(1, 0);
	vector<int> dp(num + 1, 0);
	for (int i = 1; i <= num; ++i)
		dp[i] = dp[i&(i-1)] + 1;
	return dp;
}
