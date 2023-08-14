class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // set<int> s;
        // for(auto x:nums){
        //     s.insert(x);
        // }
        // vector<int> ans;
        // for(auto x:s){
        //     ans.push_back(x);
        // }
        // for(auto x:ans){
        //     cout<<x<<" ";
        // }
        // return ans[ans.size()-k];
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto x:nums){
            if(minHeap.size()<k){
                minHeap.push(x);
            }
            else if(minHeap.size()>=k){
                if(minHeap.top()<x){
                    minHeap.pop();
                    minHeap.push(x);
                }
            }
        }
        return minHeap.top();
    }
};