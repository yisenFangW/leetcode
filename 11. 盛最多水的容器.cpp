给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

题解：
//题目拿到后，分析题目可知，求面积最小的一片区域，即最小高乘以长度，最小高为min(height[left],height[right]);
//若采用暴力求解的方法，则时间复杂度为O(n*n)，分析可知，若height[left]>=height[right]，则让--right，若height[right]<height[left]
//++left，判断条件为left<right;O(n)时间复杂度；
int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1;
	int res = 0;
	while (left < right) {
		res = max(res, min(height[left], height[right]) * (right - left));
		(height[left] > height[right]) ? --right : ++left;
	}
	return res;
}
