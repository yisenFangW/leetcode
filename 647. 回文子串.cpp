给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
注意:

输入的字符串长度不会超过1000。

题解：
//1.首先是自己写的，通过辅助函数判断字符串是否是回文字符串，然后从前开始遍历，每个遍历到结尾，也就是取到了所有的组合类型；
//勉强能够AC过，就是很简单粗暴的想法，感觉不带一丝算法的思想在里面；贴代码；
bool isSubStrings(string& s, int left, int right){
    if(s.size() == 1) return true;
    while(left <= right){
        if(s[left++] == s[right--])
            continue;
        else
            return false;
    }
    return true;
}

int countSubstrings(string s) {
    if(s.empty()) return 0;
    int res = 0;
    for(int i=0;i<s.size();++i){
        for(int j=i;j<s.size();++j){
            if(isSubStrings(s, i, j)) ++res;
        }
    }
    return res;
}
//2.看了别人的思路：考虑每个数作为中间数，往左右遍历，一旦不是回文序列，直接返回，就是这里省了时间啊，因为1方法就是在
//很多无用功上面浪费了很多时间去解决这类问题，暴力求解；然后需要注意的是，是奇数还是偶数的回文序列，注意这点就OK；贴代码；
void helper(string& s, int i, int j, int& res){
    while(i>=0 && j<s.size() && s[i--] == s[j++])
        ++res;
}

int countSubstrings(string s) {
    if(s.empty()) return 0;
    int res = 0;
    for(int i=0;i<s.size();++i){
        helper(s, i, i, res);
        helper(s, i, i+1, res);
    }
    return res;
}
