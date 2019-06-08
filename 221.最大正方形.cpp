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
