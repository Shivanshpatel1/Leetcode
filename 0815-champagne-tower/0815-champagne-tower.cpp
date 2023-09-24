class Solution {
public:
    double champagneTower(int x, int r, int c) {
        vector<vector<double>> val(101,vector<double>(101,0));
        val[0][0]=x;

        for(int i=0; i<=r; i++){
            for(int j=0; j<=i;j++){
                double temp=val[i][j];
                if(temp>1){
                    temp--;
                    temp=temp/2;
                    val[i][j]=1;
                    val[i+1][j]+=temp;
                    val[i+1][j+1]+=temp;
                }
                if(i==r && j==c)return val[i][j];
            }
        }
        return val[r][c];
    }
};