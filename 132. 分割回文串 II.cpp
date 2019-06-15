给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

题解：
//很明显的动态规划题目，难度难就难在找递推方程上面f[i] = min(j=0~i-1){f[j+1] | dp[j][i-1]>0};

//判断回文字符串的函数
void judgePalindrome(string s, int left, int right, vector<vector<bool>>& dp) {
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		dp[left][right] = true;
		--left; ++right;
	}
}

int minCut(string s) {
	if (s.empty())
		return 0;
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
  //这个地方初始化f的大小为s.size()+1,(自己写的时候这个地方并没有写成s.size()+1,而是s.size())
	vector<int> f(s.size() + 1, INT_MAX);
	for (int i = 0; i < s.size(); ++i) {
    //因为回文字符串可能有奇数或者偶数，若为奇数，则对称轴为中间元素，若为偶数，则对称轴为中间轴
    //这样写能够加速判断是否是回文子串，注意这种方法。
		judgePalindrome(s, i, i, dp);
		judgePalindrome(s, i, i + 1, dp);
	}
	f[0] = 0;
	for (int i = 1; i <= s.size(); ++i) 
		for (int j = 0; j < i; ++j) 
			if (dp[j][i - 1])
				f[i] = min(f[i], f[j] + 1);
  //return f[s.size()] - 1？？减一
	return f[s.size()] - 1;
}

//2.修改后的1代码，不用再减一了，较为容易理解一点
int minCut(string s) {
	if (s.empty())
		return 0;
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	vector<int> f(s.size(), INT_MAX);
	for (int i = 0; i < s.size(); ++i) {
		judgePalindrome(s, i, i, dp);
		judgePalindrome(s, i, i + 1, dp);
	}
	f[0] = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j <= i; ++j)
			if (dp[j][i])
				f[i] =(j == 0) ? 0 : min(f[i], f[j-1] + 1);
	}
	return f[s.size() - 1];
}

//3.参考别人写出来的更加精简的代码，将回文字符串的判断与动态规划方法进行结合，只有一个循环
int minCut(string s) {
	if (s.empty())
		return 0;
	vector<vector<bool>> p(s.size(), vector<bool>(s.size(), false));
	vector<int> dp(s.size());
	for (int i = 0; i < s.size(); ++i) {
		dp[i] = i;
		for (int j = 0; j <= i; ++j) {
			if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
				p[j][i] = true;
				dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	return dp[s.size() - 1];
}
