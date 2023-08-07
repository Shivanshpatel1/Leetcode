class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int low=0;
        int high=row*col;

        while(low<high){
            int mid = (low+high)>>1;
            if(matrix[mid/col][mid%col]==target){
                return true;
            } else if(matrix[mid/col][mid%col]<target){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return false;
    }
};