class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;

public:
    MedianFinder() {
        
    }
    /*
    1, 2, 3, 4
    */
    void addNum(int num) {
        if(min.empty()){
            min.push(num);
        }
        else{
            if(num >= min.top()){
                max.push(min.top());
                min.pop();
                min.push(num);
            }   
            else{
                max.push(num);
            }
        }
        int mins = min.size(); 
        int maxs = max.size();
        if( abs(mins-maxs) > 1){
            if(min.size() < max.size()){
                min.push(max.top());
                max.pop();
            }
            else{
                max.push(min.top());
                min.pop();
            }
        }

    }
    
    double findMedian() {
        if(min.size() == max.size()){
            return (min.top() + max.top())  / 2.0;
        }
        else if(max.size() > min.size()){
            return max.top();
        }
        return min.top(); 
    }
};
