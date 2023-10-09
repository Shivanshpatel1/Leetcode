class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int k) {
            int start=0;
    int end=arr.size()-1;
    int mid;
    int flag=0;
    int ans=-1;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]<k){
            start=mid+1;
        } else if(arr[mid]>k){
            end=mid-1;
        }else if(arr[mid]==k){
            ans=mid;
            end=mid-1;
        }
    }
    int first = ans;
    
    int low=0;
    int high=arr.size()-1;
    int ans1=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<k){
            low = mid+1;
        } else if(arr[mid]>k){
            high = mid-1;
        } else if(arr[mid]==k){
            ans1=mid;
            low=mid+1;
        }
    }
    
    int second = ans1;
    vector<int> vect;
    vect.push_back(first);
    vect.push_back(second);
    return vect;
    }
};