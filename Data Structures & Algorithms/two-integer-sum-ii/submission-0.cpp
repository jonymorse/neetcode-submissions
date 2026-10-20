class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        unordered_map<int, int> mp;
        vector<int> twoSum(2);

        for(int i = 0; i < sz; i++){
            int element = numbers[i];
            int diff = target - element;

            if(mp.count(diff)){

                int diffIndex = mp[diff] + 1;
                int elementIndex = i + 1;
                twoSum[0] = diffIndex;
                twoSum[1] = elementIndex;;
                return twoSum;
            }
            
            mp[element] = i;
        }    
        return twoSum;
        }
};
