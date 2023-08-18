
// class Flight{
//     public:
//     int from;
//     int to;
//     int price;
    
//     Flight(int from, int to, int price):from(from), to(to), price(price) {}
// };

// class cmp{
//     public:
//     bool operator()(pair<int, int> &a, pair<int, int> &b){
//         return a.second>b.second;
//     }
// };

struct cmp {
    bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        // if(a.first.second==b.first.second) return a.second<b.second;
        // else return a.first.second > b.first.second;
        return a.second>b.second;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto x:flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> q;

        q.push({{src,0}, 0});

        vector<int> distance(n, INT_MAX);
        distance[src]=0;

        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            int node = temp.first.first;
            int dist = temp.first.second;
            int s = temp.second;

            if(s>k) continue;
            //if(node==dst) return distance[dst];
            //if (dist > distance[node]) continue;

            for(auto x:adj[node]){
                int newdist = dist+x.second;
                if(newdist<distance[x.first] && s<=k){
                    distance[x.first]=newdist;
                    q.push({{x.first, newdist}, s+1});
                }
            }
        }
        if(distance[dst]!=INT_MAX) return distance[dst];
        else return -1;
    }
};