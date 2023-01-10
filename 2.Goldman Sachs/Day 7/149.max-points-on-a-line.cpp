/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    double round_to(double value, double precision = 1.0)
    {
        return std::round(value / precision) * precision;
    }
    int maxPoints(vector<vector<int>>& points) {
        map <vector<long long int>,long long int> m;
        int n=points.size();
        int xx=0;
        int yy=0;
        for(int i=0;i<n;i++)
        {
            
            int y1=points[i][1];
            int x1=points[i][0];
            for(int j=i+1;j<n;j++)
            {
                
                int y2=points[j][1];
                int x2=points[j][0];
                if(x2-x1==0)
                {
                    m[{100000000000000000,x1}]++;
                    xx++;
                }
                else
                {
                    double mm=((y2-y1)*1.0)/(1.0*(x2-x1));
                    //mm=mm*1.0;
                    double mmmm=mm*10000000;
                    mmmm=round(mmmm);
                    long long int mmm=(long long int)mmmm;
                    //cout<<mm<<endl;
                    
                    double cc=y1-mm*x1;
                    cc=cc*10000000;
                    cc=round(cc);
                    long long int ccc=(long long int)cc;
                    m[{mmm,ccc}]++;
                    xx++;
                    
                }
            }
            
        }
        double zz=0;
        for(auto it :m)
            {
                yy=-((1.0-sqrt(1.0+8*it.second))/2.0);
                if(zz<yy)
                zz=yy;
                //cout<<it.first[0]<<" "<<it.first[1]<<" "<<it.second<<endl;
            }
        //if(xx==yy)
        //cout<<xx<<" "<<yy;
        zz++;
        return zz;
    }
};
// @lc code=end

