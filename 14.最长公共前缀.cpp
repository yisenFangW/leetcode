编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

题解：
//简答题1.拿到题第一思路是将字符串根据长度进行排序，然后取所有的字符串从头开始比较，若都相等，则添加到结果字符串中
//否则输出结果字符串
string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
		return "";
	string res = "";
	sort(strs.begin(), strs.end(), [](const string& str1, const string& str2) {return str1.size() < str2.size(); });
	for (int i = 0; i < strs[0].size(); ++i) {
		char c = strs[0][i];
		for (int j = 0; j < strs.size(); ++j) {
			if (strs[j][i] != c)
				return res;
		}
		res.push_back(c);
	}
	return res;
}
