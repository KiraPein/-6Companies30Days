/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long int>> g;
        vector<long long int> mt,nw;
        vector<long long int> sel;
        for(int i=0;i<n;i++)
        {
            g.push_back({});
            mt.push_back(1000000000000000000);
            nw.push_back(0);
            sel.push_back(0);
            for(int j=0;j<n;j++)
            {
                g[i].push_back(1000000000000000000);
            }
        }
        int x=10000000000,y=0;
        for(int i=0;i<roads.size();i++)
        {
            int a=roads[i][0];
            int b=roads[i][1];
            int c=roads[i][2];
            g[a][b]=c;
            g[b][a]=c;
            if(b==0)
                swap(a,b);
            if(a==0)
            {
                nw[b]=1;
                mt[b]=c;
                if(c<x)
                {
                    x=c;
                    y=b;
                }
            }

            
        }
        
        
        sel[0]=1;
        sel[y]=1;
        for(int i=1;i<n;i++)
        {
            long long int a=mt[y];
            long long int xx=1000000000000000000;
            int yy=0;
            for(int j=0;j<n;j++)
            {
                if(sel[j]==1)
                {
                    continue;
                }
                
                long long int b=g[y][j];
                long long int c=mt[j];
                
                if(a+b<c)
                {
                    nw[j]=nw[y];
                    mt[j]=a+b;
                }  
                else if(a+b==c)
                {
                    nw[j]=nw[j]+nw[y];
                }  
                {
                    nw[j]=nw[j]%1000000007;
                    if(mt[j]<xx)
                    {
                        yy=j;
                        xx=mt[j];
                    }


                }
            }
            
            
            y=yy;
            sel[y]=1;
            
        }
        if(n==1)
        return 1;
        return (nw[n-1]%1000000007);
        
    }
};
// @lc code=end

