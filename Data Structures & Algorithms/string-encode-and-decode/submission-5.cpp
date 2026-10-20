class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        
        for(string s : strs){
            int length = s.size();
            string stringLength = to_string(length);
            encodedString += "#" + stringLength + "/" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {

        int count = 0;
        bool decodeSecret = false;
        string secretLength;
        string decodedWord;
        vector<string> decodedVector;
        for(char c : s){
            if(c == '#' && count == 0){
                decodeSecret = true;
            }
            else if(c == '/' && decodeSecret == true){
                count = stoi(secretLength);
                secretLength = "";
                decodeSecret = false;
                if(count == 0){
                    decodedVector.push_back("");
                }
            }
            else if(decodeSecret == true){
                secretLength += c;
            }
            else{
                decodedWord += c;
                --count;
                if(count == 0){
                    decodedVector.push_back(decodedWord);
                    decodedWord = "";
                }
            }
        }
        return decodedVector;
    }
};
