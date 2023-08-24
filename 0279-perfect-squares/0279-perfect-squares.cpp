class Solution {
public:

    int solve(int n, vector<int> &dp){
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int pick=0;
        int notpick=0;
        int mini=INT_MAX;
        for(int i=1; i*i<=n; i++){
            pick = 1 + solve(n-i*i, dp);
            mini=min(mini, pick);
        }
        return dp[n]=mini;
    }

    int numSquares(int n) {
        vector<int> dp(n+2, -1);
        return solve(n, dp);
    }
};

// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> memo(n+1, -1);
//         return solve(n, memo); 
//     }

// private:
//     int solve(int n, vector<int>& memo) {
//         if (n == 0) return 0;
//         if (memo[n] != -1) return memo[n];
//         int result = INT_MAX;
//         for (int i = 1; i*i <= n; i++) {
//             result = min(result, 1 + solve(n - i*i, memo));
//         }
//         return memo[n] = result;
//     }
// };