/*
 * @lc app=leetcode id=2426 lang=cpp
 *
 * [2426] Number of Pairs Satisfying Inequality
 */

// @lc code=start
class Solution {
public:

vector<vector<int>> mst;

int query(int si,int ss,int se,int l, int r, int k)
{
    if(ss>r||se<l)
    {
        return 0;
    }
        
    else if(l<=ss&&se<=r)
    {
        int ind = lower_bound(mst[si].begin(), mst[si].end(), k) - mst[si].begin();
        return mst[si].size() - ind;
    }   
    else
    {
        int mid=(ss+se)/2;
        
        return (query(si*2,ss,mid,l,r,k)+ query(si*2+1,mid+1,se,l,r,k));
    }  
}

void build( int si,int ss, int se, vector<int> &d)
{
    if(se==ss)
    {
        mst[si]={(d[ss-1])};
        return;
    }
    else
    {
        int mid=(se+ss)/2;

        build(si*2,ss,mid,d);
        build(si*2+1,mid+1,se,d);

        vector<int> v1=mst[si*2];
        vector<int> v2=mst[si*2+1];
        int i1=0,i2=0;

        while(i1<v1.size()&&i2<v2.size())
        {
            if(v1[i1]<v2[i2])
            {
                mst[si].push_back(v1[i1]);
                i1++;
            }
            else
            {
                mst[si].push_back(v2[i2]);
                i2++;
            }
        }
        while(i1<v1.size())
        {
            mst[si].push_back(v1[i1]);
            i1++;
        }
        while(i2<v2.size())
        {
            mst[si].push_back(v2[i2]);
            i2++;
        }
       

    }
    
    
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> d;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            d.push_back(nums1[i]-nums2[i]);
        }
        int siz = 1;
        while(siz <= n) siz <<= 1;
        //siz<<=1;
        mst.resize(2 * siz);
        build(1,1,n,d);
        //cout<<" "<<siz;
        long long int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int x= query(1,1,n,i+2,n,d[i]-diff) ;
            ans+=x;
        }
        return ans;
    }
};
// @lc code=end

