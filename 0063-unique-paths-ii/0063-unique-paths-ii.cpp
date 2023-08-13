class Solution {
public:

    bool issafe(int i,int j , int m , int n, vector<vector<int>>& obstacleGrid){
       if(i >= 0 && j >= 0 && i < m && j < n && obstacleGrid[i][j]!=1) return true;
       return false;
    }
    int solve(int m  , int n , int i , int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        // base case 
        if(i == m - 1 && j == n - 1) return 1;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       
        int ans = 0;
        
        // righ check 
        if(issafe(i,j+1, m , n,obstacleGrid)) ans +=  solve(m,n,i,j+1, obstacleGrid, dp);
        
        // douwn check
        if(issafe(i+1,j,m,n, obstacleGrid)) ans +=  solve(m,n,i+1,j, obstacleGrid, dp);
        
        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int> (n, -1));
        return solve(m,n,0,0, obstacleGrid, dp);
    }
};
