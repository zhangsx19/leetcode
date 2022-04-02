#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//排序 + 双指针
/*时间复杂度：O(n^2),数组排序O(NlogN)，遍历i O(n)，双指针遍历 O(n)，总体 O(NlogN)+O(n)∗O(n)=O(n^2) 
空间复杂度：O(1)*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size()<3)
        {
            return ans;
        }//特解
        sort(nums.begin(),nums.end(),less<int>());//默认升序
        if (nums[0]>0)//若 nums[0]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果
        {
            return ans;
        }
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            if (i>0)//去除重复解
            {
                if (nums[i]==nums[i-1])
                {
                    continue;
                }
            }
            
            int L=i+1,R=n-1;
            while (L<R)
            {
                int sum = nums[i]+nums[L]+nums[R];
                if (sum==0)
                {
                    vector<int> result = {nums[i],nums[L],nums[R]};
                    ans.push_back(result);
                    //难点是如何去除重复解
                    while (L<R&&nums[L]==nums[L+1]&&nums[R]==nums[R-1])//先判断L<R防止数组越界
                    {
                        L++;
                        R--;
                    }
                    if (L<R)
                    {
                        L++;
                        R--;
                    }
                    
                }
                else if (sum<0)//若和小于 0，说明 nums[L] 太小，L右移
                {
                    L++;
                }
                else{
                    R--;
                }
                
                
            }
        }
        
        
        return ans;
    }
};