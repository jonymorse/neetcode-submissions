class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end()); 
        int end = intervals[0][1]; 
        int start = intervals[0][0]; 
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= end){
                end = max(intervals[i][0], intervals[i][1]);
            }
            else{
                count++; 
                end = min(end, intervals[i][1]);
            
            }
        }

        return count; 
    }
};
