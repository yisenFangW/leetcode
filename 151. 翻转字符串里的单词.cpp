给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

题解：
1.首先的想法是将原s中的string付给一个vector容器，再将容器的值，倒过来赋值给str
实现如下：
string reverseWords(string s) {
    vector<string> vec;
    string tmp = string();
    for (int i = 0; i < s.size();++i) {
        if (s[i] == ' ' && tmp == "")
            continue;
        if (s[i] != ' ')
            tmp.push_back(s[i]);
        else {
            vec.push_back(tmp);
            tmp = string();
        }
    }
    if(tmp != "")
        vec.push_back(tmp);
    string res = string();
    for (auto iter = vec.rbegin(); iter != vec.rend(); ++iter) {
        res += *iter;
        if (iter != vec.rend()-1)
            res.push_back(' ');
    }
    return res;
}
