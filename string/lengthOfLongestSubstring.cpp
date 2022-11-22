#include<string>
#include<iostream>

/*
题目：最大不重复子字符串
给定一个字符串s，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"   输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: s = "bbbbb"   输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"   输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串
*/


class Solution
{
    public:
    
    //滑动窗口，设置两个下标，left和i，不断指向当前最大不重复字串
    //如abcaef，一开始left=i=0；遍历i，当i=3指向a时，使left=i指向b
    int lengthOfLongestSubstring(std::string originStr)
    {
        int maxLen=0;
        int left=0;
        if(originStr.length()<=1)
        {
            return originStr.length();
        }
        for(int i=0;i<originStr.length();i++)
        {
            auto substr=originStr.substr(left,i-left);
            auto index= substr.find(originStr[i]);
            if(index!=std::string::npos)//有重复
            {
                left=left+index+1;
            }
            else
            {
               substr= originStr.substr(left,i-left+1);
            }
            if(substr.length()>maxLen)
            {
                maxLen=substr.length();
            }        
        }
        return maxLen;
    }
};

int main()
{
    Solution slu;
    auto result=slu.lengthOfLongestSubstring("abcabcbb");
    std::cout<<result<< std::endl;
    return 0;
}