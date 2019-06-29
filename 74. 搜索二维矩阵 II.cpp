编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

题解：
//1.因为每行是递增的，每列也是递增的，因此判断每行的最后一个数(即最后一列)，若大于这个数，则将行row++;若小于这个数
//则列减小col--;判断条件一直是若target == matrix[row][col]，若相等则为true，则为false;否则若跳出while循环的条件
//while(r<row && col>=0)，跳出循环，则找不到target，输出false;
vector<int> dailyTemperatures(vector<int>& T) {
	vector<int> res(T.size(), 0);
	for (int i = T.size() - 2; i >= 0; --i) {
		if (T[i + 1] > T[i])
			res[i] = 1;
		else if (T[i + 1] <= T[i]) {
			if (res[i + 1] == 0)
				res[i] == 0;
			else {
				int add = res[i + 1];
				while (T[i + add] <= T[i] && res[i + add] != 0) {
					add += res[i + add];
				}
				if (T[i + add] > T[i])
					res[i] = add;
			}
		}
	}
	return res;
}
