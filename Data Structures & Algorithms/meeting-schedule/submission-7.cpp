/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int start = intervals[0].start; 
        int end = intervals[0].end; 
        
        for(int i = 1; i < intervals.size(); i++){
            int currStart = intervals[i].start;
            int currEnd = intervals[i].end;

            if(currStart < end && currEnd >= start){
                return false;
            }
            start = currStart;
            end = currEnd;
        }

        return true; 
    }
};
