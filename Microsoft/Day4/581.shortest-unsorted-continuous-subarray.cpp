/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> n;
        n=nums;
        int a=-1,b=n.size();
        sort(n.begin(),n.end());
        for(int i=0;i<n.size();i++)
        {
            if(n[i]==nums[i])
            a=i;
            else
            break;
        }
        for(int i=n.size()-1;i>=0;i--)
        {
            if(n[i]==nums[i])
            b=i;
            else
            break;
        }
        //cout<<a<<" "<<b;
        return max(0,b-a-1);
    }
};
// @lc code=end

