给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

题解：
//遇到这种佩列组合的问题，用递归递归啊，开始竟然没有想到，这题还是有几个点需要注意的；

//参数传引用的解法；
void letterCombinations(string& digits, vector<string>& dict, int level, string& out, vector<string>& res){
    //设置递归终止条件为到digits的结尾；
    if(level == digits.size()){
        res.push_back(out);
        return;   //注意这个return一定要加啊，不然就会完全停不下来；
    }
    string str = dict[digits[level] - '0'];
    //遍历并让level+1
    for(auto c:str) {
        out+=c;
        letterCombinations(digits, dict, level + 1, out, res);
        out.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    //因为是从2开始，所以前面两个为空啊
    vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string out;
    letterCombinations(digits, dict, 0, out, res);
    return res;
}

//参数不传引用的方法，时间空间复杂度更小？？
class Solution {
public:
    void letterCombinations(string& digits, vector<string>&dict, int level, string out, vector<string>& res){
        if(level == digits.size()) {
            res.push_back(out);
            return;
        }
        string str = dict[digits[level] - '0'];
        for (auto c:str)
            letterCombinations(digits, dict, level + 1, out + c, res);
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        letterCombinations(digits, dict, 0, "", res);
        return res;
    }
};
