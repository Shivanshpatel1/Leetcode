// class Solution {
// public:
//     int minDeletions(string s) {
//         unordered_map<char, int> mp;
//         for(auto x:s){
//             mp[x]++;
//         }
//         vector<int> num;
//         for(auto x:mp){
//             num.push_back(x.second);
//         }
//         priority_queue<int> pq;
//         for(auto x:num){
//             pq.push(x);
//             cout<<x<<endl;
//         }
//         int c=0;
//         int top=pq.top();
//         pq.pop();
//         while(!pq.empty()){                     //6, 4, 4, 2
//             if(pq.top()==top){                  //top=3, 
//                 c++;
//                 pq.pop();
//                 //top--;
//                 if(top>0){
//                     pq.push(top-1);
//                     top=pq.top();
//                     pq.pop();
//                 }
//             }else{
//                 top=pq.top();
//                 pq.pop();
//             }
//         }
//         return c;
//     }
// };

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> charFrequency;
        unordered_set<int> existingFrequencies;

        for (char c : s) {
            charFrequency[c]++;
        }
        priority_queue<int> maxHeap;
        for (auto freq : charFrequency) {
            maxHeap.push(freq.second);
        }

        int deletions = 0;
        while (!maxHeap.empty()) {
            int curFreq = maxHeap.top();
            maxHeap.pop();
            
            while (curFreq > 0 && existingFrequencies.count(curFreq)) {
                curFreq--;
                deletions++;
            }
            existingFrequencies.insert(curFreq);
        }
        return deletions;
    }
};