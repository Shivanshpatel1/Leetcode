class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int n=g.size();
        int m=s.size();
        int j=0, i=0;
        int c=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                c++;
                i++;
                j++;
            }else{
                i++;
            }
        }
        return c;
    }
};