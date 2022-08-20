/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int i = 0, j = 0, max = 0;
    int hash[256] = {0};
    while (i < len && j < len)
    {
        if (hash[s[j]] == 0)
        {
            hash[s[j]] = 1;
            j++;
            max = max > j - i ? max : j - i;
        }
        else
        {
            hash[s[i]] = 0;
            i++;
        }
    }
    return max;
}
// @lc code=end
