给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

题解：
//题解1:将s中这一段的string拿出来，然后排序，你不是乱序的嘛，我就给你排呗，也将p排序，然后比较两个字符串是否相等；
//然后就是悲伤的超时，尴尬
vector<int> findAnagrams1(string s, string p) {
    if(s.empty() || p.empty() || s.size() < p.size())
        return {};
    vector<int> res;
    int pn = p.size();
    sort(p.begin(), p.end());
    for(int i=0;i<s.size()-pn+1;++i){
        string tmp = s.substr(i, pn);
        sort(tmp.begin(), tmp.end());
        if(tmp == p) res.push_back(i);
    }
    return res;
}

//题解2:想到的是用一个unordered_map存储p中的元素，然后从前往后判断s中的元素是否在p的map中，
//然后又是超时，what fuck，这可是一题简单题；
vector<int> findAnagrams(string s, string p) {
    if(s.empty() || p.empty() || s.size() < p.size())
        return {};
    vector<int> res;
    int ns = s.size(), np = p.size();
    unordered_map<int, int> m;
    for(auto c:p) ++m[c];
    unordered_map<int, int> tm = m;
    bool flag = true;
    for(int i=0;i<ns-np+1;++i){
        flag = true;
        tm = m;
        for(int count=0;count<np;++count){
            if(tm.count(s[i+count]) == 0 || tm[s[i+count]] == 0) {
                flag = false;
                break;
            }
            else
                --tm[s[i+count]];
        }
        if(flag) res.push_back(i);
    }
    return res;
}

//题解3:滑动窗口，比较巧妙解决问题，设置滑动窗口的左右界限，然后减去左边的，加上右边的，再对vector的值进行判断，妙啊！
//注意这个解题的方法
vector<int> findAnagrams(string s, string p) {
    if (s.empty() || p.empty() || s.size() < p.size())
        return {};
    vector<int> win_s(26, 0), win_p(26, 0), res;
    int l = 0, r = -1;
    for(int i=0;i<p.size();++i){
        ++win_p[p[i] - 'a'];
        ++win_s[s[++r] - 'a'];
    }
    if(win_s == win_p) res.push_back(l);
    while(r < s.size()-1){
        --win_s[s[l++] - 'a'];
        ++win_s[s[++r] - 'a'];
        if(win_s == win_p)
            res.push_back(l);
    }
    return res;
}

//题解4.拿到题目之后第一想法是将p的内容存到一个hash表中，然后s从左往右运行，设置一个l和r，判断l和y之间的关系，如果差值等于p的长度
//且l和r之间的每个数都在hash表中，且hash的数值大于1。这样就判断s中存在一个p，存下l的位置：
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> m, temp;
    vector<int> res;
    int len = p.size();
    for (auto i:p)
        ++m[i];
    for (int l = 0, r = 0; l < s.size() && r < s.size();) {
        temp = m;
        while (temp.count(s[r]) && --temp[s[r]] >= 0) {
            if (len == r - l + 1) {
                res.push_back(l);
                break;
            } else
                ++r;
        }
        ++l;
        r = l;
    }
    return res;
}

//题解5:自己实现的方法，速度比较慢，看了一下别人ace比较快的的代码，通过两个vector存hashs和hashp，对比是否相等，然后删掉hashs的左侧
//加上右侧的内容，再次比较，这样会速度很快，不用s中的每个都要多次比较：
vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size())
        return {};
    vector<int> res;
    int len = p.size();
    vector<int> hashs(26, 0), hashp(26, 0);
    for (int i = 0; i < len; ++i) {
        ++hashs[s[i] - 'a'];
        ++hashp[p[i] - 'a'];
    }
    for (int i = len; i < s.size(); ++i) {
        if (hashs == hashp) {
            res.push_back(i - len);
        }
        ++hashs[s[i] - 'a'];
        --hashs[s[i - len] - 'a'];
    }
    if (hashs == hashp)
        res.push_back(s.size() - len);
    return res;
}
