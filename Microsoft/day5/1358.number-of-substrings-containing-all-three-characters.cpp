/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int win[4];
        win[0]=0;
        win[1]=0;
        win[2]=0;
        win[3]=0;
        long long int ans=0;
        int a=0,b=2;
        int n=s.length();
        int cc[n];
        s+="dd";
        for(int i=0;i<n;i++)
        {
            cc[i]=n;
        }
        
        win[s[0]-97]++;
        win[s[1]-97]++;
        win[s[2]-97]++;
        if(win[0]!=0&&win[1]!=0&&win[2]!=0)
        {
            cc[0]=2;
            a++;
            
            win[s[0]-97]--;
        }
       // cout<<s<<endl;
        while (a<n-2)
        {
            //cout<<win[0]<<" "<<win[1]<<" "<<win[2]<<" "<<a<<" "<<b<<endl;
            if(win[0]!=0&&win[1]!=0&&win[2]!=0)
            {
                cc[a]=b;
                win[s[a]-97]--;
                a++;
                continue;
            }
            if(b!=n)
            {
                b++;
                win[s[b]-97]++;
                
            }
            else
            {
                cc[a]=n;
                win[s[a]-97]--;
                a++;
            }
            
            
            
            
        }
        for(int i=0;i<n;i++)
        {
            //cout<<cc[i]<<" ";
            ans+=n-cc[i];
        }
        //cout<<" "<<ans;
        return ans;
    } 
};
// @lc code=end

