/* 向表达式添加括号后的最小结果
给你一个下标从 0 开始的字符串 expression ，格式为 "<num1>+<num2>" ，其中 <num1> 和 <num2> 表示正整数。
请你向 expression 中添加一对括号，使得在添加之后， expression 仍然是一个有效的数学表达式，并且计算后可以得到 最小 可能值。左括号 必须 添加在 '+' 的左侧，而右括号必须添加在 '+' 的右侧。
返回添加一对括号后形成的表达式 expression ，且满足 expression 计算得到 最小 可能值。如果存在多个答案都能产生相同结果，返回任意一个答案。
生成的输入满足：expression 的原始值和添加满足要求的任一对括号之后 expression 的值，都符合 32-bit 带符号整数范围。
示例 1：
输入：expression = "247+38"  输出："2(47+38)"
解释：表达式计算得到 2 * (47 + 38) = 2 * 85 = 170 。
注意 "2(4)7+38" 不是有效的结果，因为右括号必须添加在 '+' 的右侧。
可以证明 170 是最小可能值。
示例 2：
输入：expression = "12+34"  输出："1(2+3)4"
解释：表达式计算得到 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20 。
示例 3：
输入：expression = "999+999"  输出："(999+999)"
解释：表达式计算得到 999 + 999 = 1998 。

提示：
3 <= expression.length <= 10
expression 仅由数字 '1' 到 '9' 和 '+' 组成
expression 由数字开始和结束
expression 恰好仅含有一个 '+'.
expression 的原始值和添加满足要求的任一对括号之后 expression 的值，都符合 32-bit 带符号整数范围
*/
#include<iostream>
#include<map>
using namespace std;
class Solution
{
    //解体思路：暴力解法
    //分为4部分，分别将 a*（b+c）*d ，四个值算出来，求最小，然后重新拼接回去
    //以 + 的index 为中心， 左边->index 第一层循环。index->right 第二层循环
    public :
    string minizeResult(string expression)
    {
        int index=expression.find('+');
        map<string,int> map1;
        int min=INT_MAX;
        string resultStr="";
        for(int i=0;i<index;i++)
        {
            for(int j=index+1;j<expression.size();j++)
            {
                int a=i==0?1: std::stoi(expression.substr(0,i));
                int b= stoi(expression.substr(i,index-i));
                int c= stoi(expression.substr(index+1,j-index));
                int d= j==expression.size()-1?1: stoi(expression.substr(j+1,expression.size()-j-1));

                auto number=a*(b+c)*d;
                if(number<min)
                {
                    min=number;
                    resultStr = expression.substr(0, i) + "(" + expression.substr(i, j - i + 1) + ")" + expression.substr(j + 1,expression.size()- j - 1);
                }
            }
        }
        return resultStr;
    }
};

int main ()
{
    Solution slu;
    slu.minizeResult("11+345");
    return 0;
}