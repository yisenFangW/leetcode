给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

题解：
//这题拿到了就应该想到是不是递归，因为很明显终止条件之类的，都已经告诉你了，如果sum>target返回，如果sum==target将vec存入到res中去；
//设置辅助函数中多三个参数，分别是start,vec,res，start存目前在candidate中的第几个元素，去重的作用；vec是对数组的暂时存储，res存储结果；
//最后得到的函数形式为：   不需要设定sum，因为可以直接用target减去每个对应值，即可通过target与0的关系判断终止条件；
void combinationSum(vector<int>& candidates, int target, int start, vector<int>& vec, vector<vector<int>>& res){
    if(target < 0) return;
    if(0 == target) {
        res.push_back(vec);
        return;
    }
    for(int i=start;i<candidates.size();++i){
        vec.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], i,vec, res);
        vec.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.empty() || target<=0) return {};
    vector<vector<int>> res;
    vector<int> vec;
    combinationSum(candidates, target, 0, vec, res);
    return res;
}
