class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vect(n+1, true);
        vect[0]=false;
        vect[1]=false;

        int c=0;
        for(int i=2; i<n; i++){
            if(vect[i]==true){
            //c++;
            int j=2*i;
            while(j<n){
                vect[j]=false;
                j+=i;
            }
            }
        }
        
        for(auto x:vect){
            if(x==true) c++;
        }
        return (c>0) ? c-1:c;
    }
};