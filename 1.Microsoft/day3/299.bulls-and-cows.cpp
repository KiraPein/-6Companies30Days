/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
#include <string>
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s,g;
        int n=secret.length();
        for(int i=0;i<n;i++)
        {
            s.push_back(secret[i]-48);
            g.push_back(guess[i]-48);
        }
        int a=0;
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==g[i])
            {
                a++;
                s[i]=-1;
                g[i]=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==-1)
                continue;
            else
            {
                int x=s[i];
                for(int j=0;j<n;j++)
                {
                    if(g[j]==x)
                    {
                        b++;
                        g[j]=-1;
                        break;
                    }
                }
            }
            
        }
        string xx=to_string(a)+"A"+to_string(b)+"B";
        return xx;
    }
};
// @lc code=end

