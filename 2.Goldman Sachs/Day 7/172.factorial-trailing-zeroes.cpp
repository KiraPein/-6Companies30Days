/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int zz=n/5+n/25+n/125+n/625+n/(625*5)+n/(625*25);
        return zz;
    }
};
// @lc code=end

