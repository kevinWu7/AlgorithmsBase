#include<string>
#include<iostream>
class Solution
{
    public:
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