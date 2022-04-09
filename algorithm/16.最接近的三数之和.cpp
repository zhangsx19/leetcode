/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
//排序 + 双指针
/*时间复杂度：O(n^2),数组排序O(NlogN)，遍历i O(n)，双指针遍历 O(n)，总体 O(NlogN)+O(n)∗O(n)=O(n^2) 
空间复杂度：O(1)*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int sum_target_distance = INT_MAX;
        sort(nums.begin(),nums.end(),less<int>());//默认升序
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int L=i+1,R=n-1;
            while (L<R)
            {
                int sum = nums[i]+nums[L]+nums[R];
                int cur_distance = abs(sum-target);
                if (sum==target)
                {
                    return sum;   
                }
                else if (sum<target)//若和小于 0，说明 nums[L] 太小，L右移
                {
                    
                    if (cur_distance<sum_target_distance)
                    {
                        sum_target_distance = cur_distance;
                        ans = sum;
                    }
                    L++;
                }
                else{
                    if (cur_distance<sum_target_distance)
                    {
                        sum_target_distance = cur_distance;
                        ans = sum;
                    }
                    R--;
                }
                
                
            }
        }
        return ans;
    }
};
// @lc code=end

