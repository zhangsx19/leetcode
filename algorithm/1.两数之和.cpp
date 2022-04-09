/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
//排序+双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> sort_nums = nums;
        sort(sort_nums.begin(),sort_nums.end(),less<int>());//默认升序
        int n = nums.size();
        int L=0,R=n-1;
        while (L<R)
        {
            int sum = sort_nums[L]+sort_nums[R]-target;
            //难点是要返回排序前vector的下标，且vector可能有重复元素
            if (sum==0)
            {
                vector<int> ::iterator it_L = find(nums.begin(),nums.end(),sort_nums[L]);
                int index_L = it_L-nums.begin();
                vector<int> ::iterator it_R;
                if (sort_nums[L]==sort_nums[R])
                {
                    it_R = find(nums.begin()+index_L+1,nums.end(),sort_nums[R]);
                }else{
                    it_R = find(nums.begin(),nums.end(),sort_nums[R]);
                }
                int index_R = it_R-nums.begin();
                result = {index_L,index_R};
                break;
            }else if (sum<0)//若和小于 0，说明 nums[L] 太小，L右移
            {
                L++;
            }else{
                R--;
            }
            
            
        }
        return result;
            
    }
};
// @lc code=end

