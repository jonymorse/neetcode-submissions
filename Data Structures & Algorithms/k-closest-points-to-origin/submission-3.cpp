class Solution {
public:
    struct MyComparator{
        bool operator()(vector<int>& p1, vector<int>& p2){
            auto euclid = [](const vector<int>& p){
                int x = p[0];
                int y = p[1];
                int e = (x*x) + (y*y);
                return e;
            };
            return euclid(p1) > euclid(p2);

        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, MyComparator> pq;
        for(vector<int> p : points){
            pq.push(p);
        }
        vector<vector<int>> res;
        while(k > 0){
            k--;
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
