class Solution {
public:
    int bin(int i){
        int ones = 0; 
        while(i > 0){
            int r = i % 2; 
            if(r == 1) ones++; 
            i = i / 2;
        }
        return ones; 
    }
    vector<int> countBits(int n) {
        vector<int> res; 
        for(int i = 0; i <= n; i++){
            res.push_back(bin(i));
        }
        return res;
    }

};
