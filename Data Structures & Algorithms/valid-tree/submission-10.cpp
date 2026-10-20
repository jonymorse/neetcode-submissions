class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //if(edges.empty()) return true;
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n); 
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> path;
        if(hasCycle(adj, path, 0, -1)) return false;
        if(path.size() != n) return false;
        return true; 
    }
private:
    bool hasCycle(vector<vector<int>>& adj, unordered_set<int>& path, int node, int prev){
        if(path.contains(node)) return true;
        path.insert(node);
        for(auto& n : adj[node]){
            if(prev == n) continue; 
            if(hasCycle(adj, path, n, node)) return true; 
        }
        return false;
    }
};
