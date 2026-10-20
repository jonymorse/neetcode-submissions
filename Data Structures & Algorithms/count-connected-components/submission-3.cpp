class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0; 
        vector<vector<int>> adj(n);
        for(auto& nodes : edges){
            adj[nodes[0]].push_back(nodes[1]);
            adj[nodes[1]].push_back(nodes[0]); 
        }

        unordered_set<int> visited;

        for(int i = 0; i < n; i++){
            if(!visited.contains(i)){
                count++;
                dfs(adj, visited, i, -1); 
            }
        }          
        return count ;
    }
private: 
    void dfs(vector<vector<int>>& adj, unordered_set<int>& visited, int node, int prev){
        if(visited.contains(node)) return; 
        visited.insert(node);
        for(auto& n : adj[node]){
            dfs(adj, visited, n, node); 
        }
        return;
    }
};
