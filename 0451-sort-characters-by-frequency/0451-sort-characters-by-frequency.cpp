class Solution {
public:

    static bool cmp(pair<char, int> &a, pair<char, int> &b){
        if(a.second==b.second) return a.first<b.first;
        else return a.second>b.second;
    }

    string frequencySort(string s) {
        int freqTable[256]={0};

        for(int i = 0;i<s.size();i++){
            freqTable[s[i]]++;
        }

        vector<pair<char,int>> freqPair;
        for(int i = 0;i<s.size();i++){
            freqPair.push_back({s[i],freqTable[s[i]]});
        }

        sort(freqPair.begin(),freqPair.end(),cmp);

        string ans="";

        for(auto p:freqPair){
            ans+=p.first;
        }
        return ans;
    }
};