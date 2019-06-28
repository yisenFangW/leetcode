给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

题解:
//自己写的时候，感觉写起来非常冗余啊，原因是因为不知道num1和num2哪个要长，这样就得分情况写，那样就会非常复杂，写起来也不好写
//看别人的写法，因为sum = i1+i2+carry;所以要是num1和num2谁先没了，就让谁等于0即可，注意最后的一个carry，条件表达式，
//三元运算符的用法，注意用起来，这里非常好用。
string addStrings(string num1, string num2) {
	int m = num1.size() - 1;
	int n = num2.size() - 1;
	int carry = 0;
	string res = "";
	while (m >= 0 || n >= 0) {
		int i1 = (m >= 0) ? num1[m--] - '0' : 0;
		int i2 = (n >= 0) ? num2[n--] - '0' : 0;
		int sum = i1 + i2 + carry;
		carry = sum / 10;
		res.insert(res.begin(), sum % 10 + '0');
	}
	return carry ? "1" + res : res;
}
