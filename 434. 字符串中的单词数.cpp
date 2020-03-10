统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5

题解：
思路是首先去除首尾的空格，然后数空格数加1，就是字符串的个数；

int countSegments(string s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    if (s.empty())
        return 0;
    int count = 1;
    for (int i = 0; i < s.size();i++) {
        if (s[i] == ' ') {
            while (s[i] == ' ')
                i++;
            count++;
        }
    }
    return count;
}
