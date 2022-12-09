/*
题目标题：前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2 输出: [1,2]
示例 2:
输入: nums = [1], k = 1 输出: [1]
 
提示：
1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class solution
{
    //解体思路：
    //滑动窗口，left 和i，用left-1 代表出现的频率
    //用两个vector-key，value来分别存放 数字和该数字出现的频率次数，最终返回key
    //这道题挺恶心的地方是，有各种情况，由于判断条件写的不是很好，导致代码较长
    //似乎用if(num[i]==num[i-1]) else 这种判断比较好
    //执行用时：16 ms, 在所有 C++ 提交中击败了46.65%的用户
    //内存消耗：13.1 MB, 在所有 C++ 提交中击败了90.51%的用户
     public :
     vector<int> topKFrequent(vector<int> & nums,int k)
     {
         vector<int> key;
         vector<int> value;
         std::sort(nums.begin(),nums.end());
         int left=0;
         int current=0;
         if(nums.size()<=1)
         {
            return nums;
         }
         for(int i=0;i<nums.size();i++)
         {
            if(i!=0&&nums[i]!=nums[i-1])
            {
                current=nums[i-1];
                if(key.size()<k)
                {  
                    key.push_back(current);
                    value.push_back(i-left);
                }
                else
                {
                    if((i-left)> *min_element(value.begin(),value.end()))//若比已有数据大
                    {
                        int temp_index=  min_element(value.begin(),value.end())-value.begin();
                        value[temp_index]=i-left;
                        key[temp_index]=current;
                    }
                }
                left=i; 
            }
            if(i==nums.size()-1)
            {
                if(value.size()==0) //为了适配 {1,1}这种情况
                {
                    key.push_back(nums[0]);
                    return key;
                }
                if(value.size()<k)//为了适配{1,2},2 这种情况
                {
                    key.push_back(nums[i]);
                    return key;
                }
                if((i-left+1)> *min_element(value.begin(),value.end()))//若比已有数据大,为了适配{1,2,2,3,3,3} 2 这种情况
                {
                    int temp_index=  min_element(value.begin(),value.end())-value.begin();
                    value[temp_index]=i-left+1;
                    key[temp_index]=nums[i];
                }
            }
        } 
        return key;
     }
};

int main()
{
    solution sol;
    vector<int> vec={1,2};
    cout<<sol.topKFrequent(vec,2).size()<<endl;
    return 0;
}