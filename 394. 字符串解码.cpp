给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

题解：
//这题拿到题后有些懵逼，不知道该怎么下手，看了别人的题解，才知道该怎么写，还是有很多细节，需要注意，一不小心，还是会出错；
//详细解题方案，在程序中说明更好理解：

//给的例子的格式是 字母+数字+[..]
string decodeString(string s, int &i) {
    string res = string();
    int n = s.size();
    //判断i是否到了s的末尾，或者是到了‘]’，因为在循环中遇到了']'之后，会进行++i,所以会跳过‘]’;
    while(i<n && s[i]!=']'){
        //判断s[i]是不是字母，若为字母，则直接加上
        if(s[i]<'0' || s[i]>'9')
            res+=s[i++];
        else {
            int count = 0;
            //判断是不是数字，将所有的数字还原，因为括号前面必须是有数字的，所以不用怕出错；
            while (s[i] >= '0' && s[i] <= '9')
                count = count * 10 + s[i++] - '0';
            //++i跳过左括号；
            ++i;
            //获取两个括号中的内容；
            string t = decodeString(s, i);
            //跳过右括号
            ++i;
            while (count-- > 0)
                res += t;
        }
    }
    return res;
}

string decodeString(string s) {
    if(s.empty()) return "";
    int i = 0;
    return decodeString(s, i);
}
