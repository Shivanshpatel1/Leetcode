class Solution {
public:

    void merge(vector<int>& nums, int s, int e, int mid){
        int i=s;
        int j=mid+1;
        int k=s;
        vector<int> temp;
        while(i<=mid && j<=e){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=e){
            temp.push_back(nums[j++]);
        }
        
        for (int x = s; x <= e; x++) {
            nums[x] = temp[x-s];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e) return;

        int mid=(s+e)/2;

        //left
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);

        merge(nums, s, e, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};