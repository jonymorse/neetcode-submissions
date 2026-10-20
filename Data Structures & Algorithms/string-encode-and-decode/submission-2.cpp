class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedWord = "";
        for(string s : strs){
            int sLength = s.size();
            string lengthString = to_string(sLength);
            encodedWord += "#" + lengthString + "/";
            for(char c : s){
                encodedWord +=c;
            }
        }
        return encodedWord;
    }

    vector<string> decode(string s) {
        vector<string> decodedVector;
        string decodedString;
        string decodedCount;
        bool count = false;
        int length = 0;
        for(char c : s){
            if(c == '#' && length == 0){
                count = true;
            }
            else if(c == '/' && count == true){
                length = stoi(decodedCount);
                if(length == 0){
                    decodedVector.push_back(decodedString);
                    decodedString = "";                    
                }
                count = false;
                decodedCount = "";
            }
            else if(count == true){
                decodedCount += c;
            }
            else{
                decodedString += c;
                length--;
                if(length == 0){
                    decodedVector.push_back(decodedString);
                    decodedString = "";                    
                }
            }            
        }
        return decodedVector;
    }
};
