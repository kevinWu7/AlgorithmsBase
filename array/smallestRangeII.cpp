/*
给你一个整数数组 nums，和一个整数 k 。
对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成 nums[i] + k 或 nums[i] - k 。
nums 的 分数 是 nums 中最大元素和最小元素的差值。
在更改每个下标对应的值之后，返回 nums 的最小 分数 。

示例 1：
输入：nums = [1], k = 0 .  输出：0
解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 
示例 2：
输入：nums = [0,10], k = 2 输出：6
解释：将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
示例 3：
输入：nums = [1,3,6], k = 3 输出：3
解释：将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。

提示：
1 <= nums.length <= 104
0 <= nums[i] <= 104
0 <= k <= 104
*/
#include<iostream>
#include<vector>
using namespace std;
class solution
{
    //解题思路：
    //先排序，然后将nums在i处分割，通过遍历i，计算所有最大-最小的情况,如下图
    //         *
    //    *  *   *
    //  *  *   *
    //   *   
    public:
    int smallestRangeII(vector<int>&nums,int k)
    {
        std::sort(nums.begin(),nums.end());
        int length=nums.size();
        int minValue=nums[length-1]-nums[0];
        for(int i=0;i<nums.size();i++)
        {
           auto max= std::max(nums[i]+k,nums[length-1]-k);
           auto min=std::min(nums[0]+k,nums[i+1]-k);
           if(minValue>(max-min))
           {
              minValue=max-min;
           }
        }
        return minValue;
    }
};

int main()
{
    solution sol;
    vector<int> vec ={7,8,8};
    std::cout<< sol.smallestRangeII(vec,5)<<std::endl;
}