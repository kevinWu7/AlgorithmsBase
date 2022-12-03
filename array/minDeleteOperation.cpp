/*
题目：使数组可以被整除的最少删除次数
给你两个正整数数组 nums 和 numsDivide 。你可以从 nums 中删除任意数目的元素。
请你返回使 nums 中 最小 元素可以整除 numsDivide 中所有元素的 最少 删除次数。如果无法得到这样的元素，返回 -1 。

如果 y % x == 0 ，那么我们说整数 x 整除 y 。
示例 1：
输入：nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]    输出：2
解释：
[2,3,2,4,3] 中最小元素是 2 ，它无法整除 numsDivide 中所有元素。
我们从 nums 中删除 2 个大小为 2 的元素，得到 nums = [3,4,3] 。
[3,4,3] 中最小元素为 3 ，它可以整除 numsDivide 中所有元素。
可以证明 2 是最少删除次数。
示例 2：
输入：nums = [4,3,6], numsDivide = [8,2,6,10] 输出：-1
解释：
我们想 nums 中的最小元素可以整除 numsDivide 中的所有元素。
没有任何办法可以达到这一目的。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //暴力解法：
    //先对nums排序
    //再对numsDivide循环，若全部能整除，则直接返回i
    //这个解法是非常低效的，10^5次方的数据，就耗时很久了
    int minOperations(std::vector<int> &nums, std::vector<int> &numsDivide)
    {
        std::sort(nums.begin(), nums.end());
        int originLength = nums.size();
        int divideLength = numsDivide.size();
        int divideIndex = 0;
        for (int i = 0; i < originLength; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) //若有重复，直接continue
            {
                continue;
            }
            divideIndex = 0;
            while (numsDivide[divideIndex] % nums[i] == 0)
            {
                divideIndex++;
                if (divideIndex == divideLength) //说明执行到了numsDivede的最后一个元素，即能完全整除
                {
                    return i; // i就是删除的index
                    break;
                }
            }
        }
        return -1;
    }
    
    //解法二：
    //能被numDivide所有整除的最小数，其实就是被numsDivide的最大公约数n，能被n整除的最小数。
    //故求最大公约数后，遍历即可
    int minOperations1(std::vector<int> &nums, std::vector<int> &numsDivide)
    {
        int gcd = numsDivide[0];
        for (int i = 0; i < numsDivide.size(); i++)
        {
            gcd = std::__algo_gcd(gcd, numsDivide[i]);
        }
        std::sort(nums.begin(), nums.end());
        for(int index=0;index<nums.size();index++)
        {
            if(gcd%nums[index]==0)
            {
                return index;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solu;
    std::vector<int> v1 = {3,2,6,2,35,5,35,2,5,8,7,3,4};
    std::vector<int> v2 = {105,70,70,175,105,105,105};
    auto count = solu.minOperations1(v1, v2);
    std::cout<<count<<std::endl;
    return 0;
}