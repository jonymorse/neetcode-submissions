class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res; 
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i = 0; i < intervals.size(); i++){
            
            int start = intervals[i][0];
            int end = intervals[i][1]; 

            if(res.back()[0] >= start || res.back()[1] >= end || res.back()[1] >= start){
                res.back()[0] = min(res.back()[0], start);
                res.back()[1] = max(res.back()[1], end);
            }
            else{
                res.push_back(intervals[i]); 
            }

        }
        return res;
    }
};
