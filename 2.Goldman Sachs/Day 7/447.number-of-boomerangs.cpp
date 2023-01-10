/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
class Solution {
public:
    long long int l(vector<int> p1,vector<int> p2)
    {
        int x1=p1[0];
        int y1=p1[1];
        int x2=p2[0];
        int y2=p2[1];
        long long int xx=(long long int)(x2-x1);
        xx=xx*xx;
        long long int yy=(long long int)(y2-y1);
        yy=yy*yy;
        long long int zz=xx+yy;
        zz=(zz);
        return zz;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        long long int ans=0;
        
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            map<long long int,long long int> m;
            vector<int> p1=points[i];
            for(int j=0;j<n;j++)
            {
                vector<int> p2=points[j];
                long long int xx=l(p1,p2);
                m[xx]++;
            }
            for(auto it:m)
            {
                //cout<<i<<" "<<it.first<<" "<<it.second<<endl;;
                long long int zz=it.second;
                ans+=zz*(zz-1);
            }
        }
        return ans;
    }
};
// @lc code=end

