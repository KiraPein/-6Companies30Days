/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <string>
#include <bitset>
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int tot;
        vector<int> one;
        for(int i=0;i<pow(2,9);i++)
        {
            string s = std::bitset< 9>(i).to_string();

            //cout <<i<<" ";
            one.clear();
            tot=0;
            for(int j=0;j<9;j++)
            {
                if(s[j]=='1')
                {
                    one.push_back(9-j);
                    tot+=9-j;
                }
                    
            }
            if(one.size()==k&&tot==n)
            {
                ans.push_back(one);
                //cout<<i<<" ";
            }
            //cout<<tot<<" ";
        }
        return ans;
    }
};
// @lc code=end

