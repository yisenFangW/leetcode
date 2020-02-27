编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

题解：
1.首先想遍历s，如果是原音，就放到vector中存起来，然后倒置再重新遍历赋值
string reverseVowels(string s) {
    vector<char> vec;
    for (auto i : s)
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' ||
            i == 'U')
            vec.push_back(i);
    if (vec.empty())
        return s;
    reverse(vec.begin(), vec.end());
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' ||
            s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            s[i] = vec[count++];
    return s;
}

2.双指针遍历，注意判断left和right的大小关系
string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while ((s[left] != 'a' && s[left] != 'e' && s[left] != 'i' && s[left] != 'o' && s[left] != 'u' &&
               s[left] != 'A' && s[left] != 'E' && s[left] != 'I' && s[left] != 'O' && s[left] != 'U') && left < s.size()-1)
            left++;
        while((s[right] != 'a' && s[right] != 'e' && s[right] != 'i' && s[right] != 'o' && s[right] != 'u' &&
              s[right] != 'A' && s[right] != 'E' && s[right] != 'I' && s[right] != 'O' && s[right] != 'U') && right > 0)
            right--;
        if(left < right)
            swap(s[left++], s[right--]);
    }
    return s;
}
