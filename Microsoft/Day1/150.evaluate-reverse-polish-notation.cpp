/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s;
        int ii=0;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            char ch=tokens[i][0];
            cout<<tokens[i]<<" ";
            if(48<=ch&&ch<=57||tokens[i].length()>1)
            {
                s.push_back(stoi(tokens[i]));
                ii++;
            }
            else
            {
                int b=s[--ii];
                int a=s[--ii];
                
                s.pop_back();
                s.pop_back();
                if(ch=='+')
                {
                    s.push_back((a+b));
                }
                if(ch=='*')
                {
                    s.push_back((a*b));
                }
                if(ch=='-')
                {
                    s.push_back((a-b));
                }
                if(ch=='/')
                {
                    s.push_back((a/b));
                }
                ii++;
                
            }
        }
        return s[0];
    
    }
};
// @lc code=end

