给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

题解：
//这题的解决方案，是按照递归的方法去解，首先遍历整个二维网格，看二维网格中是否有与word第一个元素相同的元素，有的话，就
//对这个元素的进行判断，然后进行递归遍历，判断正误，值得注意的是，我第一遍写，没有通过，是因为{{"a", "a"}}, "aaa"这个
//例子，因为会对返回来重新判断，所以结果有错，需要用一个visited数组进行判断，有没有遍历过，重点看是visited的赋值次数与位置；
// 要注意搜过的就不能再往回搜了，所以需要确认一下；
bool exist(vector<vector<char>>& board, int row, int col, string word, int index, vector<vector<bool>>& visited){
    if(index >= word.size())
        return true;
    if(row >= board.size() || col >= board[0].size() || visited[row][col])
        return false;
    bool res = false;
    if(word[index] == board[row][col]) {
        visited[row][col] = true;
        // 这个地方要传进去index+1，不能传++index;
        res = exist(board, row + 1, col, word, index + 1, visited) ||
              exist(board, row - 1, col, word, index + 1, visited) ||
              exist(board, row, col + 1, word, index + 1, visited) ||
              exist(board, row, col - 1, word, index + 1, visited);
        visited[row][col] = false;
    }
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word.empty()) return true;
    if(board.empty()) return false;
    vector<vector<bool>> visited((board.size(), (board[0].size(), false)));
    for(int row=0;row<board.size();++row){
        for(int col=0;col<board[0].size();++col){
            if(board[row][col] == word[0])
                if(exist(board, row, col, word, 0, visited))
                    return true;
        }
    }
    return false;
}
