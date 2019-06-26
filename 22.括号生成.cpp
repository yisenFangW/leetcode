给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

题解：
//1.开始没有做出来，想通过递归来实现，但是递归的条件写的不行，最后结果不对。
//看视频的思路第一步是将所有的可能集合都写出来，也就是2*2n次方，这个时间复杂度太高了
//然后再进行筛选。第二步是判断将第一步的结果进行筛选，在进行递归时，传入left和right,
//right<=left;left == right == n;有了这两个筛选条件，即能够筛选出所有符合条件的括号；
void generate(int left, int right, vector<string>& res, string& s) {
	if (left == 0 && right == 0) {
		res.push_back(s);
		return;
	}
	if (left) {
		s += "(";
		generate(left - 1, right, res, s);
		s.pop_back();
	}
	if (right > left) {
		s += ")";
		generate(left, right - 1, res, s);
		s.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	if (n <= 0)
		return res;
	string s = "";
	generate( n, n, res, s);
	return res;
}
