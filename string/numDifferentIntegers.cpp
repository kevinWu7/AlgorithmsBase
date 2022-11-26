#include <iostream>
#include <ctype.h>
#include <map>
using namespace std;

/*
题目：字符串中不同整数的数目
给你一个字符串 word ，该字符串由数字和小写英文字母组成。
请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123  34 8  34" 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）："123"、"34"、"8" 和 "34" 。
返回对 word 完成替换后形成的 不同 整数的数目。
只有当两个整数的 不含前导零 的十进制表示不同， 才认为这两个整数也不同。

示例 1：
输入：word = "a123bc34d8ef34"  输出：3
解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
示例 2：
输入：word = "leet1234code234"  输出：2
示例 3：
输入：word = "a1b01c001"  输出：1
解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。

提示：
1 <= word.length <= 1000
word 由数字和小写英文字母组成
*/
class solution
{
public:
    //解体思路
    //双指针，left和i,当i遇到英文时，取出num，并存入map
    //注意点：一开始就在结尾添加‘a’，防止最后一位为数字的情况，前导0通过while来删除
    int numDifferentIntegers(string word)
    {
       // word=word+'a';// 让结尾必定为英文字符，保证最后一位为数字时，不需要额外判断
        int length = word.length(); 
        int left= 0;
        map<string, char> map1;
        for (int i = 0; i < length; i++)
        {
            if (islower(word[i])) //a1b2
            {
                string num = word.substr(left, i - left);
                while (num.length() > 1 && num.find('0') == 0) //循环干掉前导0
                {
                    num = num.substr(1, num.length() - 1);
                }
                if (num.length() > 0 && map1.find(num) == map1.end())
                {
                    map1[num] = ' ';
                }
                left = i + 1;
            }
        }
        return map1.size();
    }
};

int main()
{
    solution slu;
    int count = slu.numDifferentIntegers("a3e5f6");
    std::cout << count << std::endl;
}