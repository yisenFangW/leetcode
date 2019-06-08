题目描述：
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

解题：
(1)暴力求解，在拿到题目后，想了几分钟，没有想到好的办法，就采用暴力求解的办法，依此对数组中每一个数字进行遍历，求得每一个数字所对应的正方形的最大，
然后用一个最大值变量保存算得的最大值。

int judgeSize(vector<vector<char>>& matrix, int row, int col) {
	if (matrix[row][col] - '0' == 0)
		return 0;
	int i = row, j = col, size = 1;
	while (++row < matrix.size() && ++col <matrix[0].size()) {
		for (int k = j; k <= col; ++k)
			if (matrix[row][k] - '0' == 0 )
				return size;
		for (int k = i; k <= row; ++k)
			if (matrix[k][col] - '0' == 0)
				return size;
		size = (row - i + 1)*(col - j + 1);
	}
	return size;
}

int maximalSquare(vector<vector<char>>& matrix) {
	int len = matrix.size();
	if (len == 0)
		return 0;
	int size = 0, maxSize = 0;
	int col = matrix[0].size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < col; ++j) {
			size = judgeSize(matrix, i, j);
			if (size > maxSize)
				maxSize = size;
		}
	}
	return maxSize;
}
