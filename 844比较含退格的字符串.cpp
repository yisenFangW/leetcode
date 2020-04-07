给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：

1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。

// 这个地方开始没有想到用栈去搞，一个很适合用栈去做的题目，当是#则抛出已有的，如果不是#则压栈；
bool backspaceCompare(string S, string T) {
    if(S == T) return true;
    stack<char> ss;
    stack<char> st;
    for(auto s:S){
        if(s != '#')
            ss.push(s);
        if(s == '#' && !ss.empty()){
            ss.pop();
        }
    }
    for(auto t:T){
        if(t != '#')
            st.push(t);
        if(t == '#' && !st.empty()){
            st.pop();
        }
    }
    if(ss == st) return true;
    return false;
}


