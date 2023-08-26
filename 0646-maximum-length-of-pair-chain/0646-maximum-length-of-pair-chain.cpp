// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end());
//         int c=1;
//         vector<int> ans;
//         int i;
//         for(i=0; i<pairs.size()-1; i++){
//             if(pairs[i][1]<pairs[i+1][0]){
//                 pairs[i+1][0] = pairs[i][0];
//                 pairs[i+1][1] = max(pairs[i][1], pairs[i+1][1]);
//                 c++;
//             }
//         }
//         if(pairs[i-1][0]<pairs[i][1]) c++;
//         return c;
//     }
// };
class Solution {
public:
    static bool sortsecond(vector<int>& a, vector<int>& b){
        return b[1] > a[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), sortsecond);
        int ans =1;
        int prev= pairs[0][1];
        for(int i=1 ; i<pairs.size();i++){
            if(pairs[i][0] > prev){
                ans++;
                prev = pairs[i][1];
            }
        }
        return ans;
    }
};