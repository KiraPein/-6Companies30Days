/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0;
        int fin=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            ans+=i*nums[i];
            sum+=nums[i];
        }
        fin=ans;
        for(int i=0;i<n;i++)
        {
            ans=ans-sum+(n)*nums[i];
            cout<<ans<<" ";
            fin=max(fin,ans);
        }
        return fin;
    }
};
// @lc code=end

