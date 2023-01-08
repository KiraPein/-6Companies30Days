/*
 * @lc app=leetcode id=1227 lang=cpp
 *
 * [1227] Airplane Seat Assignment Probability
 */

// @lc code=start
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double prob[n];
        double occ=1.0/n;
        prob[0]=1.0/n;

        for(int i=1;i<n;i++)
        {
            
            prob[i]=1-occ;
            //cout<<prob[i]<<" "<<occ<<endl;
            occ+=(1-prob[i])*(1.0/(n-i));
        }
        return prob[n-1];
    }
};
// @lc code=end

