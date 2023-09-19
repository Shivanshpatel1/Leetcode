#include <algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0; i<n; i++){
            int index=abs(nums[i]);
            if(nums[index]<0){
                ans=index;
                return ans;
            }else{
                nums[index]*=-1;
            }
        }
        return -1;
        }   
};