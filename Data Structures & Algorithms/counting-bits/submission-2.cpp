class Solution {
public:

    int count(int n){
        int c = 0; 
        while(n){
            n &= (n - 1);
            c++; 
        }

        return c; 
    }
    vector<int> countBits(int n) {
        
        vector<int> out; 

        for(int i = 0; i <= n; i++){
            out.push_back(count(i));
        }

        return out; 
    }
};
