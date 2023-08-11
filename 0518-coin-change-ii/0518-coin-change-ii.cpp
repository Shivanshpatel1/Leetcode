class Solution {
public:
    int c=0;
    int solve(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if(ind>=coins.size()){
            return 0;
        }
        if(dp[amount][ind]!=-1) return dp[amount][ind];

        int take = solve(amount-coins[ind], coins, ind, dp);
        int nottake = solve(amount, coins, ind+1, dp);
        return dp[amount][ind]=take+nottake;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+2, vector<int> (coins.size()+2, -1));
        int x = solve(amount, coins, 0, dp);
        return x;
    }
};