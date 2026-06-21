class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;

        for(vector<int> &edge:edges){
            int u=edge[0];
            int v=edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool> visited(n, false);

        queue<int> que;
        que.push(source);
        visited[source] = true;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            if(node == destination) return true;

            for(auto &v : mp[node]){
                if(!visited[v]){
                    que.push(v);  
                    visited[v] = true;
                }
            }
        }
        return false;
    }
};