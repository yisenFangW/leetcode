实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

题解：
//题目本身是一个很简单的题目，但是在写的过程中，有一些小细节需要注意，还有写的方式，如i只需便利到m-n即可，
//剪枝操作，结果加速。
//注意这个地方的剪枝加速过程
int strStr(string haystack, string needle) {
	if (needle.empty())
		return 0;
	if (haystack.empty())
		return -1;
	int m = haystack.size();
	int n = needle.size();
	if (m < n)
		return -1;
	for (int i = 0; i <= m-n; ++i) {
		if (haystack[i] == needle[0]) {
			int index = i, j = 0;
			while (i < m && j < n && haystack[i] == needle[j]) {
				++i;
				++j;
			}
			if (j == needle.size())
				return index;
			else
				i = index;
		}
	}
	return -1;
}
