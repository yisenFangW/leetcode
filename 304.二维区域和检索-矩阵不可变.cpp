给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。


上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。

解题：
（1）拿到这一题第一个思路就是直接遍历，直接暴力求解，暴力求解的程序如图（时间复杂度太大，通过不了）：
class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		region = matrix;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (region.empty())
			return 0;
		int row = region.size();
		int col = region[0].size();
		if (row1 >= row || col1 >= col)
			return 0;
		if (row2 >= row)
			row2 = row - 1;
		if (col2 >= col)
			col2 = col - 1;
		int sum = 0;
		for (int i = row1; i <= row2; ++i) {
			for (int j = col1; j <= col2; ++j) {
				sum += region[i][j];
				//cout << region[i][j] << " ";
			}
		}
		return sum;
	}
private:
	vector<vector<int>> region;
};

（2）改进版，求出一个辅助数组dp[row+1][col+1],给辅助数组求和，求每一个dp[i][j]的值，取得时候直接取就ok(动态规划)
class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return;
		//取dp的大小比matrix的行列均大1，然后就不用判断i,j是否等于0；（注意vector的resize操作）
		dp.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
		for (int i = 1; i <= matrix.size(); ++i) 
			for (int j = 1; j <= matrix[0].size(); ++j)
				//注意dp[i][j]的条件判断
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i-1][j-1];
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		//注意这里的条件判断，画图清晰一点
		return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
	}

private:
	vector<vector<int>> dp;
};
