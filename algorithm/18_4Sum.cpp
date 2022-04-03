#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//排序 + 双指针 + 求和溢出
/*时间复杂度：O(n^2),数组排序O(NlogN)，遍历 O(n)，双指针遍历 O(n)，总体 O(NlogN)+O(n)∗O(n)*O(n)=O(n^3) 
空间复杂度：O(1)*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size()<4)
        {
            return ans;
        }//特解
        sort(nums.begin(),nums.end(),less<int>());//默认升序
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            if (i>0&&nums[i]==nums[i-1])//去除重复解
            {
                continue;
            }
            for (int j = i+1; j < n; j++)
            {
                if (j>i+1&&nums[j]==nums[j-1])
                {
                    continue;
                }
                int L=j+1,R=n-1;
                while (L<R)
                {
                    int sum1 = nums[i]+nums[j];
                    int sum2 = nums[L]+nums[R];//注意防止结果溢出（>INT_MAX)
                    if (sum1==target-sum2)
                    {
                        vector<int> result = {nums[i],nums[j],nums[L],nums[R]};
                        ans.push_back(result);
                        //难点是如何去除重复解
                        while (L<R&&nums[L]==nums[L+1]&&nums[R]==nums[R-1])//先判断L<R防止数组越界
                        {
                            L++;R--;
                        }
                        if (L<R)
                        {
                            L++;R--;
                        }
                        
                    }else if (sum1<target-sum2)
                    {
                        L++;
                    }else{
                        R--;
                    }
                    
                    
                }
                
            }
            
            
            
        }
        
        
        return ans;
    }
};
int main(){
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;
    Solution a;
    vector<vector<int> > ans = a.fourSum(nums,target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}