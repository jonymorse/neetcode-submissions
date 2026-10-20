class Solution {
public:
    int countSubstrings(string s) {
        int count = 0; 
        for(int i = 0; i < s.size(); i++){
            count++; 
            int odd = pal(s, i-1, i+1, 0);
            int even = pal(s, i, i+1, 0); 
            count += odd + even;
        }
        return count ;
    }
private:
    int pal(string& s, int l, int r, int len){
        if(l < 0 || r > s.size() - 1){
            return len;
        }
        if(s[l] == s[r]){
            len++; 
            return pal(s, l - 1, r + 1, len); 
        }
        return len;
    }
};
