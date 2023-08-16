class Solution {
public:

    

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int maxi=INT_MIN;
        //first window
        for(int i=0; i<k; i++){
            //chhote elements remove kardo
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        //rest maate karo

        for(int i=k; i<nums.size(); i++){
            if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
            }
            //print(nums, dq);
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            //print(nums, dq);
             ans.push_back(nums[dq.front()]);


        }
        
        return ans;
    }
};