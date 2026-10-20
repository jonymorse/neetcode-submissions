class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> res; 
        bool inserted = false;

        for(int i = 0; i < intervals.size(); i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            

            if(currEnd < newStart){
                res.push_back(intervals[i]);
            }
            else if(currStart > newEnd){
                if(!inserted){
                    res.push_back({newStart, newEnd});
                    inserted = true;
                }
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                break;
            }
            else{
                newStart = min(newStart, currStart);
                newEnd = max(newEnd, currEnd);
            }
        }
        if(!inserted) res.push_back({newStart, newEnd});
        return res; 
    }
};
