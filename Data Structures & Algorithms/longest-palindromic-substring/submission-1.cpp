class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0; 
        int r = 0;
        string sub = s.substr(0,1);
        for(int i = 0; i < s.size(); i++){

                int odd = pal(s,i-1,i+1,0);
                int even = pal(s,i,i+1,0);
                int len = max(odd, even); 
                if(len > sub.size()){
                        int pos = i - ( (len - 1) / 2 ); 
                        sub = s.substr(pos, len);  
                }
        }
        return sub; 
    }
private:
        int pal(string& s, int l, int r, int len){
                if(l < 0 || r > s.size() - 1){
                        return len; 
                }
                if(s[l] == s[r]){
                        len =  r - l + 1; 
                        l--; 
                        r++; 
                        return pal(s,l,r,len);
                }
                return len; 
        }
        
};
