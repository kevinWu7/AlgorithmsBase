#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 给你一个字符串 s，找到 s 中最长的回文子串。
// 解释:回文的意思是，将字符串翻转和原字符串一样。如aba就是回文字符串
// 示例 1： 输入：s = "babad"  输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2： 输入：s = "cbbd"  输出："bb"
// 示例 3： 输入：s = "aabafeabaa"  输出："aba"
// 提示：
// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成

//解法一：双循环暴力解法
//第一层循环，从头循环字符串；第二层循环，从字符串尾部开始遍历
//若发现两个字符相同，则判断i-x原字符串和x-i反转字符串是否相同，相同则记录，直至找出最大长度的
class solution
{
public:
    std::string longestPalindrome(std::string originStr)
    {
        if (originStr.length() == 0)
        {
            return "";
        }
        auto reverseStr = originStr;
        int length = originStr.length();
        std::string maxStr = "";
        int maxLength = 0;
        std::reverse(reverseStr.begin(), reverseStr.end());
        for (int i = 0; i < originStr.length(); i++)
        {
            for (int x = originStr.length() - 1; x >= 0; x--)
            {
                if (x - i + 1 <= maxLength) //若将要计算的长度超出直接break,节约时间
                {
                    break;
                }
                if (x < i) //只能和对应的字符串比较，若超出直接break，如：aabafeabaa，应返回aba，若不加判断返回aaba
                {
                    break;
                }
                if (originStr[i] == originStr[x])
                {
                    auto subStr = originStr.substr(i, x - i + 1);
                    if (subStr == reverseStr.substr(length - 1 - x, x - i + 1))
                    {
                        if (subStr.length() > maxStr.length())
                        {
                            maxStr = subStr;
                            maxLength = maxStr.length();
                        }
                    }
                }
            }
        }
        std::cout << maxStr << std::endl;
        return maxStr;
    }
};

//解法二：中心扩展
//回文字符串的特点是，以中间某个字符为中心，若两边各取一个字符，是相同的话，那么该字符必为回文
//首先通过while循环找出相同的字符，相同字符串必为回文，然后标记下标，如abbbc，则i=1，right=3；然后根据i和right作为边界向两边扩展
class solution2
{
public:
    std::string longestPalindrome(std::string originStr)
    {
        int maxLength = 0;
        std::string maxString = "";
        int right = 0;
        if(originStr.length()<=1)
        {
            return originStr;
        }
        //从左向右循环
        for (int i = 0; i <= originStr.length() - 1; i++)
        {
            right = i;
            while (originStr[i] == originStr[right + 1])
            {
                right++;
            }
            if(right - i + 1>maxLength)
            {
                maxString = originStr.substr(i, right - i + 1);
                maxLength = maxString.length();
            }

            //中心扩散
            for (int count = 1; count < originStr.length() / 2 + 1; count++)
            {
                if(i-count<0||right+count>originStr.length()-1)
                {
                    break;
                }
                if (originStr[i - count] == originStr[right + count])
                {
                    if ((count * 2 + right - i + 1) > maxLength)
                    {
                        maxString = originStr.substr(i - count, count * 2 + right - i + 1);
                        maxLength = maxString.length();
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return maxString;
    }
};

int main()
{
    solution2 slu;
    std::cout << slu.longestPalindrome("ababd");
}