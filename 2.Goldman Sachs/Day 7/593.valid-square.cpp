/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
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

    long long int len(int x1,int y1,int x2,int y2)
    {
        long long int xx=(long long int)(x2-x1);
        xx=xx*xx;
        long long int yy=(long long int)(y2-y1);
        yy=yy*yy;
        long long int zz=xx+yy;
        zz=(zz);
        return zz;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        long long int  side=10000000000000;
        long long int diag=0;
        int b=0;
        side=min(side,len(p1[0],p1[1],p2[0],p2[1]));
        side=min(side,len(p1[0],p1[1],p3[0],p3[1]));
        side=min(side,len(p1[0],p1[1],p4[0],p4[1]));
        diag=max(diag,len(p1[0],p1[1],p2[0],p2[1]));
        diag=max(diag,len(p1[0],p1[1],p3[0],p3[1]));
        diag=max(diag,len(p1[0],p1[1],p4[0],p4[1]));
        if(diag!=2*side||side==0)
        b=1;
        if(len(p1[0],p1[1],p2[0],p2[1])==side)
        {
            if(l(p1,p3)==side)
            {
                if(l(p1,p4)!=diag||l(p2,p4)!=side||l(p3,p4)!=side||l(p2,p3)!=diag)
                b=1;

            }
            else if(l(p1,p3)==diag)
            {
                if(l(p1,p4)!=side||l(p2,p3)!=side||l(p2,p4)!=diag||l(p3,p4)!=side)
                b=1;
            }
            else
            b=1;
            
        }
        else if(l(p1,p2)==diag)
        {
            if(l(p1,p3)!=l(p1,p4)||l(p2,p3)!=l(p2,p4)||l(p2,p4)!=l(p1,p4)||l(p1,p4)!=side||l(p3,p4)!=diag)
            b=1;
        }
        else
        b=1;

        if(b==1)
        return false;
        else
         return true;
        
    }
};
// @lc code=end

