class Solution {
public:

    string find(string &str){
        // unordered_map<char, int> mp;
        // for(auto x:str) mp[x]++;
        // string ret="";
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        //     ret+=to_string(x.second);
        //     ret+=x.first;
        // }
        // return ret;
        string ret="";
        int count=0;
        for(int i=0;i<str.size(); i++){
            count++;
            if(i==str.size()-1 || str[i]!=str[i+1]){
                ret+=to_string(count);
                ret+=str[i];
                count=0;
            }
        }
        return ret;
    }

    string solve(int n){
        if(n==1){
            return "1";
        }
        string temp = solve(n-1);
        string ans = find(temp);
        return ans;
    }

    string countAndSay(int n) {
        return solve(n);
    }
};