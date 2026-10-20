class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> neighbors(numCourses); 
        for(auto& pre : prerequisites){
            neighbors[pre[1]].push_back(pre[0]);
        }
        for(auto& pre : prerequisites){
            unordered_set<int> path; 
            int course = pre[1]; 
            if(hasCycle(neighbors, path, course)){
                return false; 
            }
        } 
        return true;
    }
private: 
    bool hasCycle(vector<vector<int>>& neighbors, unordered_set<int>& path, int course){
        if(path.find(course) != path.end()) return true; 
        if(neighbors[course].empty()) return false; 
        path.insert(course);
        for(auto& n : neighbors[course]){
            if(hasCycle(neighbors, path, n)){
                return true; 
            }
        }

        return false; 
    }
};
