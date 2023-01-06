/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> prev[n];
        vector<int> fwd[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                else
                {
                    if(nums[j]%nums[i]==0)
                    {
                        prev[j].push_back(i);
                        fwd[i].push_back(j);
                    }
                        
                }    
            }
        }
        int arr[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            arr[i][j]=0;
        }
        vector<int> last={1},l2;
        int li=0;
        int lll=0;
        for(int i=0;i<n;i++)
        {
            l2.clear();
            if(last.size()==0)
            {
                
                break;
            }
            
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                continue;
               
                for(int k=0;k<last.size();k++)
                {
                    
                    if(last[k]>nums[j])
                        break;
                    if(i==1&&j==2)
                    cout<<nums[j]<<" "<<last[k]<<endl;
                    if(nums[j]%last[k]==0&&nums[j]!=last[k]||(i==0&&nums[j]==1))
                    {
                        arr[i][j]=1;
                        l2.push_back(nums[j]);
                        li=i;
                        lll=nums[j];
                        for(int m=0;m<fwd[j].size();m++)
                        {
                            if(arr[i][fwd[j][m]]==1)
                            break;
                            arr[i][fwd[j][m]]=1;
                            l2.push_back(nums[fwd[j][m]]);
                            lll=nums[fwd[j][m]];
                        }


                        break;
                    }
                }
            }
            last=l2;
            sort(last.begin(),last.end());
           
        }
        
        cout<<li<<" ";
        vector<int> finn;
        finn.push_back(lll);
        for(int i=li-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(lll%nums[j]==0&&arr[i][j]==1&&lll!=nums[j])
                {
                    lll=nums[j];
                    finn.push_back(lll);
                    break;
                }
            }
        }
        return finn;
        
    }
};
// @lc code=end

