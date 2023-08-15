class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> vis(numCourses, 0);
        // for(int i=0; i<numCourses; i++){
        //     int x = prerequisites[i][0];
        //     int y = prerequisites[i][1];
        //     adj[x].push_back(y);
        // }
        for (auto prereq : prerequisites) {
            int x = prereq[1];
            int y = prereq[0];
            adj[x].push_back(y);
        }

        //inwards
        vector<int> inwards(numCourses, 0);
        for(auto x:adj){
            for(auto y:x){
                inwards[y]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inwards[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto x: adj[front]){
                if(!vis[x]){
                    inwards[x]--;
                    if(inwards[x]==0){
                        q.push(x);
                        vis[x]=1;
                    }
                }
            }
        }

        if(ans.size()==numCourses) return true;
        else return false;


    }
};