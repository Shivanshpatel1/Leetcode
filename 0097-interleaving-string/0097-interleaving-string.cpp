class Solution {
public:

    bool solve(string &s1, string &s2, string &s3, int i1, int i2, int i3, vector<vector<int>>&dp){
        //base case
        if(i3==s3.size()){
            return true;
        }
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(i1<s1.size() && i2<s2.size() && s3[i3]==s1[i1] && s3[i3]==s2[i2]){
            return dp[i1][i2]=solve(s1, s2, s3, i1+1, i2, i3+1, dp) || solve(s1, s2, s3, i1, i2+1, i3+1, dp);
        }else if(i1<s1.size() && s3[i3]==s1[i1]){
            return dp[i1][i2]=solve(s1, s2, s3, i1+1, i2, i3+1, dp);
        }else if(i2<s2.size() && s3[i3]==s2[i2]){
            return dp[i1][i2]=solve(s1, s2, s3, i1, i2+1, i3+1, dp);
        }
       return false;
    }

    bool isInterleave(string &s1, string &s2, string &s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        vector<vector<int>>dp(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};