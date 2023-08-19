class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<int, int>> adj[n];
         for(auto x:roads){
             adj[x[0]].push_back({x[1], x[2]});
             adj[x[1]].push_back({x[0], x[2]});
         }

         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
         q.push({0, 0});
         vector<long long> arr(n, LLONG_MAX);
         vector<int> count(n, 0);
         count[0]=1;
         int MOD = (int)(1e9+7);

        while(!q.empty()){
             auto temp=q.top();
             q.pop();
             int node=temp.second;
             long long t=temp.first;

            for(auto x:adj[node]){
                //Aiya hu fasavu chhu
                 long long time = (long long)(t+x.second);
                 if(time<arr[x.first]){
                     arr[x.first]=time;
                     q.push({time, x.first});
                     //Same hoi to jya thi avyu etla path to resej ne
                     count[x.first] = count[node];
                 }else if(time==arr[x.first]){
                     //same hoi distance to to count na ena pela nu node laisu and jetlu aa banave chhe ae laisu
                     count[x.first] = (count[x.first] + count[node])%MOD;
                 }
            }
        }
        return count[n-1]%MOD;
    }
};

