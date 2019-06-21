给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

题解：
/1.开始想用将字符转数字的方式，然后再转成二进制，但是那样写会报错，因为二进制的数值可能会非常大，数字存储不下来，只能用string进行存储
//还有一点要注意，这里的s[i]是字符，要减去'0'之后才是正式的数字值。
long switchTo(string s) {
	if (s.empty())
		return 0;
	int n = s.size() - 1;
	long num = 0;
	for (int i = n; i >= 0; --i)
		num += (s[i] - '0') * pow(2, n - i);
	return num;
}

//这题转化为int算，不是很实际，因为他可能会用很大的数作为测试用例，导致你不能通过
string addBinary2(string a, string b) {
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	string res = "";
	long sum = switchTo2(a) + switchTo2(b);
	while (sum) {
		res.push_back((char)('0' + sum % 2));
		sum /= 2;
	}
	int left = 0, right = res.size() - 1;
	while (left < right)
		swap(res[left++], res[right--]);
	return res;
}

//2.用string进行计算的方法，写的很长啊，自己看都要崩溃了
string addBinary(string a, string b) {
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	string res = "";
	int left = a.size();
	int right = b.size();
	int count = 0;
	while (left > 0 && right > 0) {
		int sum = (a[left-1] - '0') + (b[right-1] - '0') + count;
		if (sum == 0)
			res.push_back('0');
		else if (sum == 1) {
			res.push_back('1');
			count = 0;
		}
		else if (sum == 2) {
			res.push_back('0');
			count = 1;
		}
		else
			res.push_back('1');
		--left; --right;
	}
	while (left) {
		if (a[left - 1] - '0' + count == 0)
			res.push_back('0');
		else if (a[left - 1] - '0' + count == 1) {
			res.push_back('1');
			count = 0;
		}
		else {
			res.push_back('0');
			count = 1;
		}
		--left;
	}
	while (right) {
		if (b[right - 1] - '0' + count == 0)
			res.push_back('0');
		else if (b[right - 1] - '0' + count == 1) {
			res.push_back('1');
			count = 0;
		}
		else {
			res.push_back('0');
			count = 1;
		}
		--right;
	}
	if (count == 1)
		res.push_back('1');
	left = 0; right = res.size() - 1;
	while (left < right)
		swap(res[left++], res[right--]);
	return res;
}

//3.精简一点的方法
string addBinary(string a, string b) {
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	string res = "";
	int left = a.size() - 1;
	int right = b.size() - 1;
	int carry = 0;
	while (left >= 0 || right >= 0) {
		int aNum = left >= 0 ? a[left--] - '0' : 0;
		int bNum = right >= 0 ? b[right--] - '0' : 0;
		int sum = aNum + bNum + carry;
		res = to_string(sum % 2) + res;
		carry = sum / 2;
	}
	if (carry)
		res = '1' + res;
	return res;
}
