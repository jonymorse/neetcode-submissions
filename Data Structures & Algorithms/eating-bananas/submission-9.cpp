class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        double lo = 1;
        double hi = *max_element(piles.begin(), piles.end());
        double ans = hi;
        while(lo <= hi){
            double mid = floor((hi + lo) / 2.0); 
            double totalTime = 0.0; 
            for(int& p : piles){
                totalTime += ceil(p / mid); 
            }
            if(totalTime <= h){
                ans = min(ans, mid);
                hi = mid-1; 
            }
            else{
                lo = mid+1; 
            }
        }
        return ans;
    }
};
