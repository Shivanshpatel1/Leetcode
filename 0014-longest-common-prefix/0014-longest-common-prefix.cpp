class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string f=strs[0];
        int ind;
        int flag=0;
        if(strs.size()==1){
            return f;
        }
        for(int i=0; i<f.length(); i++){
            char ch = f[i];
            
            for(int j=1; j<strs.size(); j++){
                string temp=strs[j];
                
                if(temp[i]!=ch || temp.length()==i){
                    ind=i;
                    flag=1;
                    break;
                }else{
                    ind=i+1;
                }               
            }
            if(flag==1){
                break;
            }
        }
        string ans;
        for(int i=0; i<ind; i++){
            ans+=f[i];
        }
        return ans;
    }
};