/*
 * @lc app=leetcode id=2344 lang=cpp
 *
 * [2344] Minimum Deletions to Make Array Divisible
 */

// @lc code=start
class Solution {
public:

    int gcd(int a, int b)
    {
        if (a == 0)
        return b;
        return gcd(b % a, a);
    }
    
    int findGCD(int arr[], int n)
    {
        int result = arr[0];
        for (int i = 1; i < n; i++)
        {
            result = gcd(arr[i], result);
        
            if(result == 1)
            {
            return 1;
            }
        }
        return result;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=numsDivide.size();
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=numsDivide[i];
        }
        int z=findGCD(arr,n);
        sort(nums.begin(),nums.end());
        int ans=10000000;
        for(int i=0;i<nums.size();i++)
        {
            if(z%nums[i]==0)
            {
                ans=i;
                break;
            }
        }
        if(ans==10000000)
        ans=-1;
        return ans;
    }
};
// @lc code=end

