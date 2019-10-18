所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。

示例：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC", "CCCCCAAAAA"]

//题解：
//1.用一个map存从前到后的，每十个字符为一个子串的字符串，然后再遍历map存到vector作为结果返回；
//这是第一想法，应该还有更简单的方式；可以用一个set来存，如果set中有就直接存入vector中？
vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() <= 10)
        return {};
    vector<string> vec;
    map<string, int> m;
    for (int i = 0; i <= s.size() - 10; ++i) {
        ++m[string(s, i, 10)];
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > 1)
            vec.push_back(it->first);
    }
    return vec;
}
