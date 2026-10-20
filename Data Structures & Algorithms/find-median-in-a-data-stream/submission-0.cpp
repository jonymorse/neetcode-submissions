class MedianFinder {
private: 
    double currntMedian; 
    vector<int> stream; 
    int* mid; 
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        stream.push_back(num);
        sort(stream.begin(), stream.end());
    }
    
    double findMedian() {
        int size = stream.size(); 
        if(size == 0) return 0.0; 
        if(size % 2 == 0){
            double f = stream[size/2];
            double b = stream[(size/2)-1]; 
            return (f+b) / 2.0 ;
        }
        return stream[size/2]; 
    }
};
