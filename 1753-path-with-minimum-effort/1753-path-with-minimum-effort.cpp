class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<int>> dist(heights.size(), vector<int> (heights[0].size(), INT_MAX));

        minHeap.push({0, {0, 0}});
        dist[0][0]=0;

        while(!minHeap.empty()){
            auto currpath = minHeap.top();
            minHeap.pop();
            int curdist = currpath.first;
            int ci = currpath.second.first;
            int cj = currpath.second.second;


            //Djikstra Greedy chhe etle peli vaar maaj answer avi jase
            if(ci==heights.size()-1 && cj==heights[0].size()-1){
                return dist[ci][cj];
            }

            int dr[4] = {1, -1, 0, 0};
            int dc[4] = {0, 0, 1, -1};

            for(int k=0; k<4; k++){
                int nr = ci+dr[k];
                int nc = cj+dc[k];
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size()){
                    int newdist = max(curdist, abs(heights[ci][cj]-heights[nr][nc]));
                    if(newdist<dist[nr][nc]){
                        //AIYA UPDATE KARVANU RAI JAAI CHHE BANEV NEEEE
                        dist[nr][nc]=newdist;
                        minHeap.push({newdist, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};