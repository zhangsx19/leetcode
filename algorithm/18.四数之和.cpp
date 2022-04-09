/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
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

// @lc code=end

