/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:

    bool over(vector<int> a, vector<int> b)
    {
        if(a[0]<=b[0]&&b[0]<a[2]&&a[1]<=b[1]&&b[1]<a[3])
            return false;
        if(a[0]<b[2]&&b[2]<=a[2]&&a[1]<b[3]&&b[3]<=a[3]) 
            return false;
            return true;   
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> min,max;
        min={1000000,1000000};
        max={-1000000,-1000000};
        int n=rectangles.size();

        for(int i=0;i<n;i++)
        {
            vector<int> a=rectangles[i];
            if(a[0]<=min[0]&&a[1]<=min[1])
            {
                min[0]=a[0];
                min[1]=a[1];
            }
            if(a[2]>=max[0]&&a[3]>=max[1])
            {
                max[0]=a[2];
                max[1]=a[3];
            }    

        }
        long long int ma=0;
        ma=max[0]-min[0];
        ma=(long long int)(ma);
        ma=ma*(max[1]-min[1]);
        long long int area=0;
        int f=0;
        for(int i=0;i<n;i++)
        {
            long long int maa=(long long int)(rectangles[i][2]-rectangles[i][0]);
            maa=maa*(rectangles[i][3]-rectangles[i][1]);
            //cout<<maa<<endl;
            area+=maa;
           
            // if(f==1)
            // break;
        }
         map <pair<int,int>,int> vv;
        for(int i=0;i<n;i++)
        {
            vv[{rectangles[i][0],rectangles[i][1]}]++;
            vv[{rectangles[i][2],rectangles[i][3]}]++;
            vv[{rectangles[i][0],rectangles[i][3]}]++;
            vv[{rectangles[i][2],rectangles[i][1]}]++;
        }
        for(auto it:vv)
        {
            int a=it.first.first;
            int b=it.first.second;
            if((a==min[0]&&b==min[1])||(a==max[0]&&b==max[1])||(a==min[0]&&b==max[1])||(a==max[0]&&b==min[1]))
            {
                if(it.second%2==0)
                {
                    f=1;
                    //cout<<a<<" . "<<b<<endl;
                    break;
                }
            }
            else
            {
                if(it.second%2==1||it.second>4)
                {
                    f=1;
                    //cout<<a<<" "<<it.second<<endl;
                    break;
                }
            }
        }
        //cout<<f<<" "<<area<<" "<<ma;
        if(f==0&&area==ma)
        //cout<<min[0]<<" "<<min[1]<<" "<<max[0]<<" "<<max[1]<<" ";
        return true;
        else
         return false;
    }
};
// @lc code=end

