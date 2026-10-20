class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        for(auto& e : edges){
            if(e[0] == e[1]) return false;
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> path;
        for(int i = 0; i < edges.size(); i++){
            int node = edges[i][0];
            if(!path.contains(node) && i > 0) return false; 
            path.clear();
            if(hasCycle(adj, path, node, node)){
                return false;
            }
        }
        return true; 
    }
private:
    bool hasCycle(vector<vector<int>>& adj, unordered_set<int>& path, int node, int prev){
        if(path.contains(node)) return true;
        if(adj[node].empty()) return false;
        path.insert(node);
        for(auto& n : adj[node]){
            if(prev == n) continue; 
            if(hasCycle(adj, path, n, node)) return true; 
        }
        return false;
    }
};
