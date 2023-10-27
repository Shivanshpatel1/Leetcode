class Solution {
public:
    string longestPalindrome(string s) {
        int st=0, n=s.length(), max_len=1;
        for(int i=0 ; i<n ; i++){
            int l=i, r=i;
            while(r<n-1 && s[r]==s[r+1]){
                r++;
            }
            i=r;
            while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                l--;r++;
            }
            if(max_len < r-l+1){
                st=l;
                max_len=r-l+1;
            }
        }
        return s.substr(st, max_len);
    }
};