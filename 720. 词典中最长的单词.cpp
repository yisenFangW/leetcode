给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。

若无答案，则返回空字符串。

示例 1:

输入: 
words = ["w","wo","wor","worl", "world"]
输出: "world"
解释: 
单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
示例 2:

输入: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
输出: "apple"
解释: 
"apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
注意:

所有输入的字符串都只包含小写字母。
words数组长度范围为[1,1000]。
words[i]的长度范围为[1,30]。

题解：这题的要求是找到最长的字符串，然后字符串是字典序最小，还要看是否是由字符串一个一个累加而来；
自己想没想到思路，看了题解，首先排序，再在排序之后的，插入一个hash set，判断字符串的长度是否为1，或者字符串
前面的内容是否存在与hash表中，若存在，则判断与res的长度对比，还是挺经典的；
string longestWord(vector<string> &words) {
    string res = "";
    sort(words.begin(), words.end());
    unordered_set<string> s;
    for (auto word:words) {
        if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
            if (word.size() > res.size()) res = word;
            s.insert(word);
        }
    }
    return res;
}
