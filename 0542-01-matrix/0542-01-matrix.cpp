class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> vis (mat.size(), vector<bool> (mat[0].size(), false));
        vector<vector<int>> ans (mat.size(), vector<int> (mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(!vis[i][j] && mat[i][j]==0){
                    q.push({{i, j}, 0});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int d=temp.second;
            int r=temp.first.first;
            int c=temp.first.second;
            ans[r][c]=d;
            int drow[4]={1, -1, 0, 0};
            int dcol[4]={0, 0, 1, -1};
            for(int i=0; i<4; i++){
                int nr=r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && !vis[nr][nc]){
                    q.push({{nr, nc}, d+1});
                    vis[nr][nc]=true;
                }
            }
        }
        return ans;
    }
};