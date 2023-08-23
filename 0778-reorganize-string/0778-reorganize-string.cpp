class cons{
    public:
    bool operator()(pair<char, int> a, pair<char, int> b){
        return a.second<b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, cons> maxHeap;
        for(auto x:mp){
            if(x.second>0)  maxHeap.push({x.first, x.second});
        }
        string ans;
        while(maxHeap.size()>1){
            pair<char, int> temp1 = maxHeap.top();
            maxHeap.pop();
            pair<char, int> temp2 = maxHeap.top();
            maxHeap.pop();

                ans.push_back(temp1.first);
                temp1.second--;
            

                ans.push_back(temp2.first);
                temp2.second--;

            if(temp1.second>0){
                maxHeap.push(temp1);
            }
            if(temp2.second>0){
                maxHeap.push(temp2);
            }
        }
        int size = ans.size();
        char last;
        if(size){
            last = ans[size-1];
        }
        if(maxHeap.size()==1){
            pair<char, int> temp=maxHeap.top();
            if(last!=temp.first && temp.second==1){
                ans.push_back(temp.first);
            }else{
                return "";
            }
        }
        return ans;
    }
};