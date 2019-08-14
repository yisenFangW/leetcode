给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。

数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

示例:

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"
注:

letters长度范围在[2, 10000]区间内。
letters 仅由小写字母组成，最少包含两个不同的字母。
目标字母target 是一个小写字母。

题解：
//如果为'z'则返回第一个，通过二分找到一个坐标值，然后从这个坐标值一直往后遍历，找到第一个大于这个数的值返回，如果找到最后一个还是没有找到这个值
//那么就返回数组中的第一个数啊；
char nextGreatestLetter(vector<char>& letters, char target) {
    if(target == 'z') return letters.front();
    sort(letters.begin(), letters.end());
    int left = 0, right = letters.size()-1;
    while(left < right){
        int mid = left + (right-left)/2;
        if(letters[mid] < target)
            left = mid+1;
        else
            right = mid;
    }
    for(int i=left;i<letters.size();++i)
        if(letters[i] > target)
            return letters[i];
    return letters[0];
}





