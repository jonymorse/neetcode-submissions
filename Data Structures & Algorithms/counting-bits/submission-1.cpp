class Solution {
public:
    int bin(int n){
        int res = 0; 
        while(n > 0){
            if(n % 2 == 1) res++;
            n = n / 2;
        }
        return res; 
    }
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i = 0; i <= n ; i++){
            res.push_back(bin(i));
        }
        
        return res;
    }
};
