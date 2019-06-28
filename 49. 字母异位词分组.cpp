给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序

题解：
//1.自己的想法，是先将vector<string>按照单词的长度排序，若单词长度相同，将单词放入到map中，进行与后面单词的比较，
//若相同，则记录交换与比较单词附近的单词位置，++count，一直比较到最后截止，但是这样写会有些冗余，超出时间范围。
bool compare(const string &s1, const string &s2) {
	unordered_map<char, int> umap1;
	for (auto c : s1)
		++umap1[c];
	for (auto c : s2) {
		if (umap1[c] == 0)
			return false;
		else
			--umap1[c];
	}
	return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	if (strs.empty())
		return res;
	sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {return s1.size() < s2.size(); });
	for (int i = 0; i < strs.size();) {	
		vector<string> vec{ strs[i] };
		int count = 1;
		for (int j = i + 1; j < strs.size(); ++j) {
			if (strs[j].size() > strs[i].size()) {
				break;
			}
			if (compare(strs[i], strs[j])) {
				vec.push_back(strs[j]);
				swap(strs[j], strs[i + count]);
				++count;
			}
		}
		res.push_back(vec);
		i += count;
	}
	return res;
}
//2.看得别人的思路，本来自己其实也是有这个思路的，但是没有想到将string放入到unordered_map中存储(umap的设置为unordered_map<string,vector<string>>)，
//设置临时变量string tmp作为key,最后遍历unordered_map;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	if (strs.empty())
		return res;
	unordered_map<string, vector<string>> umap;
	for (auto str : strs) {
		string tmp = str;
		sort(tmp.begin(), tmp.end());
		umap[tmp].push_back(str);
	}
	for (auto i = umap.begin(); i != umap.end(); ++i)
		res.push_back(i->second);
	return res;
}










