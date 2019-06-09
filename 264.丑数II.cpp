编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

//1.有了263.丑数那题的经验，拿过来直接写，结果时间超时，哈哈，意料之中（每个都要算一遍丑数，确实费时）
bool isUgly(int num) {
	if (num < 1)
		return false;
	while (num != 1) {
		if (!(num % 2))
			num /= 2;
		else if (!(num % 3))
			num /= 3;
		else if (!(num % 5))
			num /= 5;
		else
			return false;
	}
	return true;
}

int nthUglyNumber(int n) {
	int count = 1;
	while (n) 
		if (isUgly(count++))
			--n;
	return count - 1;
}
//2.想用动态规划的方法直接写
//动态规划的思路，开始想到了，但是没写，最后看了答案写的；
int nthUglyNumber(int n) {
	vector<int> res(1, 1);
	int i2 = 0, i3 = 0, i5 = 0;
	while (--n) {
		int m2 = 2 * res[i2], m3 = 3 * res[i3], m5 = 5 * res[i5];
		int num = min(m2, min(m3, m5));
		res.push_back(num);
		if (num == m2) ++i2;
		if (num == m3) ++i3;
		if (num == m5) ++i5;
	}
	return res.back();
}
