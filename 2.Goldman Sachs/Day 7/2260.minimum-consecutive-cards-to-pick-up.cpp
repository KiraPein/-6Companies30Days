/*
 * @lc app=leetcode id=2260 lang=cpp
 *
 * [2260] Minimum Consecutive Cards to Pick Up
 */

// @lc code=start
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,vector<int>> m;
        int n=cards.size();
        for(int i=0;i<n;i++)
        {
            int x=cards[i];
            m[x].push_back(i);
        }
        int ans=10000000;
        for(auto it:m)
        {
            vector<int> v=it.second;
            int y=v[0];
            for(int i=1;i<v.size();i++)
            {
                int y=v[i-1];
                int z=v[i];
                ans=min(ans,z-y+1);
            }
        }
        if(ans>1000000)
        return -1;
        return ans;
    }
};
// @lc code=end

