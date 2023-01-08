/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 */

// @lc code=start
class Solution {
public:

    int m=1000000007;
    long long int power(long long int x,long long int y, int p)
    {
 
    // Initialize answer
        long long int res = (long long int)1;
    
        // Check till the number becomes zero
        while (y > 0) {
    
            // If y is odd, multiply x with result
            if (y % 2 == 1)
                res = (res * x)%m;
    
            // y = y/2
            y = y >> 1;
    
            // Change x to x^2
            x = (x * x)%m;
        }
        return res % p;
    }

    long long int roll1(long long int s, int ch,int i )
    {
        long long int z=power(27,i,m);
        long long int zz=((ch-96)*z)%m;
        zz+=s;
        zz=zz%m;
        return zz;
    }
    long long int roll2(long long int s, int ch,int i )
    {
        s=s*27;
        s=s%m;
        s+=ch-96;
        s=s%m;
        return s;
    }
    string longestPrefix(string s) {
        long long int x=0,y=0,z=0;;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            x=roll1(x,s[i],i);
            y=roll2(y,s[n-i-1],i);
            if(x==y&&s[i]==s[n-1])
            z=i+1;
        }
        cout<<z<<endl;
        return s.substr(0,z);
    }
};
// @lc code=end

