class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
    unordered_map<int, int> freq;
    vector<int> topK; 
    for(int elements : nums){
        freq[elements]++;
    }
    for(auto& kv : freq){
        topK.push_back(kv.first);
    }
    sort(topK.begin(), topK.end(), 
    [&freq](int& a,int& b){
        return freq[a] > freq[b];
    });

    topK.resize(k);
    return topK;
    }
};
