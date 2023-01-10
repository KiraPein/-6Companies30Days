/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
vector<int> d;
vector<int> dd;
    void bfs(int i,vector<vector<int>> & preq,vector<vector<int>> &fwd)
    {
        for(int j=0;j<fwd[i].size();j++)
        {
            dd[fwd[i][j]]++;
            if(preq[fwd[i][j]].size()==dd[fwd[i][j]])
            {
                d.push_back(fwd[i][j]);
                bfs(fwd[i][j],preq,fwd);
            }
            
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> preq,fwd;
        int n=numCourses;
        int m=pre.size();
        for(int i=0;i<n;i++)
        {
            preq.push_back({});
            fwd.push_back({});
        }
        for(int i =0;i<m;i++)
        {
            int a=pre[i][0];
            int b=pre[i][1];
            preq[a].push_back(b);
            fwd[b].push_back(a);
        }
        for(int i=0;i<n;i++)
            dd.push_back(0);
        
        for(int i=0;i<n;i++)
        {
            if(preq[i].size()==0)
            {

                d.push_back(i);
                bfs(i,preq,fwd);
            }
        }
        if(d.size()==n)
        {
            return true;
        }
        else
    
        return false;
    }
};
// @lc code=end

