class Solution {
private:
    vector<int> visited;
    unordered_map<int, vector<int>> adj;

public:
    int countComponents(int n, vector<vector<int>>& edges) {    
        visited.resize(n, 0);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bfs(i);
                count++;
            }
        }
        return count;
    }

    void bfs(int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto cur : adj[cur]) {
                if(!visited[cur]) {
                    visited[cur] = true;
                    q.push(cur);
                }
            }
        }

    }
};
