/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
class Solution {
public:
vector<vector<int>> g,t;
vector<int> arr;
vector<int> bb;

    int bfs(int i,int ti,vector<int> &amt)
    {
        int aa=amt[bb[ti]];
        //cout<<i<<" "<<ti<<" "<<endl;
        int x=0;
        if(bb[ti]==i)
        {
            x=amt[i]/2;
            amt[i]=0;
        }
        else
        {
            amt[bb[ti]]=0;
            x=amt[i];
        }
        //cout<<i<<" "<<ti<<" "<<x<<endl;
        int y=0;
        for(int j=0;j<t[i].size();j++)
        {

            int zz=bfs(t[i][j],ti+1,amt);
            //cout<<"infor"<<i<<" "<<ti<<" "<<x<<endl;
            if(j==0)
            y=zz;
            y=max(y,zz);
        }
        amt[bb[ti]]=aa;
        //cout<<"ans"<<i<<" "<<(x+y)<<" "<<endl;
        return (x+y);
        
    }
    void build(int x)
    {
        for(int i=0;i<g[x].size();i++)
        {
            if(g[x][i]!=arr[x])
            {
                arr[g[x][i]]=x;
                t[x].push_back(g[x][i]);
                build(g[x][i]);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n=edges.size()+1;
        for(int i=0;i<n;i++)
        {
            g.push_back({});
            t.push_back({});
            arr.push_back(-2);
            
        }

        for(int i=0;i<n-1;i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        arr[0]=-1;
        build(0);
        bb.push_back(bob);
        while(bob!=0)
        {
            bob=arr[bob];
            bb.push_back(bob);
        }
        for(int i=0;i<n;i++)
        {
            bb.push_back(0);
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<t[i].size();j++)
        //     {
        //         cout<<t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int z=bfs(0,0,amount);
        
        return z;
    }
};
// @lc code=end

