给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

题解：
//1.这题的意思就是将0,1,2排序，因为只有0,1,2所以排序就简单了，可以有多种排序的方法说到排序，怎么能没有冒泡呢，首先上一个冒泡
//但是肯定想想也不是冒泡，不会这么简单，虽然通过了
void sortColors(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 1; j < nums.size() - i; ++j) {
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j - 1]);
		}
	}
}

//2.因为数组中只有0,1,2三个数，所以可以用一个数组分别存储0,1,2的数量，再对nums进行赋值
void sortColors(vector<int>& nums) {
	int num[3] = { 0,0,0 };
	for (int i = 0; i < nums.size(); ++i)
		++num[nums[i]];
	int index = 0;
	for (int j = 0; j < 3; ++j)
		for (int i = 0; i < num[j]; ++i) {
			nums[index++] = j;
		}
}

//3.题目要求进行一次遍历？第二种方法用了两次遍历；一次遍历需要记录下左侧和右侧的位置，
//这种方法参考https://www.cnblogs.com/grandyang/p/4341243.html
void sortColors(vector<int>& nums) {
	int red = 0, blue = nums.size() - 1;
  //当i进行到blue的位置时候，因为此时后面已经都是2，顺序已经排好，所以不用再遍历
	for (int i = 0; i <= blue; ++i) {
    //当nums[i] == 0,让red向前移动一格
		if (nums[i] == 0)
			swap(nums[i], nums[red++]);
		else if (nums[i] == 2)
      //对应于nums[i] == 2,blue位置放好后减1，需要将i--，因为将原blue的数字替换过来到blue-1的地方，可能与i存在重叠
			//这里的i必须要减1,若不减1,对{1,2,0}这种情况就不对了
			swap(nums[i--], nums[blue--]);
	}
}



