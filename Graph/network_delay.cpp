//Question on Djiksta algorithm

/*There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
*/

class Solution {
public:
    int fillVis(set<int>& vis, vector<int>& dis){
        int min = INT_MAX, minI = -1;
        for(int i =0;i<dis.size();i++){
            if(dis[i]< min && vis.find(i)==vis.end())
                min = dis[i], minI =i;
        }
        return minI;
    }
//     void dfs(vector<vector<int>>& t,queue<int>& q,vector<int> dis,int N,int k){
        
//     }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N,INT_MAX);
        for(int i =0;i<times.size();i++){
            times[i][0]--; times[i][1]--;
        }
        // vector<int> vis(N,0);
        set<int>vis;
        // vis[k-1] = 1;
        dis[K-1] = 0;
        if(times.size()==1 && times[0][0] != K-1) return -1;
        for(int j =0;j<N;j++){
            int u = fillVis(vis,dis);
            // vis[u] = 1;
            vis.insert(u);
            
            for(int i =0;i<times.size();i++){
                if(times[i][0]==u){
                    int v = times[i][1];
                    // if(vis[v]==0 && dis[u]!=INT_MAX)
                     if(vis.find(v)==vis.end() && dis[u]!=INT_MAX){
                        if(dis[u]+ times[i][2] < dis[v])
                            dis[v] = times[i][2] + dis[u];
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i =0;i<N;i++){
            if(vis.find(i)==vis.end()) return -1;
            if(dis[i]>ans && i!=K-1) ans = dis[i]; 
        }
        return ans;
    }
};