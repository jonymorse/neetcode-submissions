class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        
        unordered_map<char, int> mp;
        priority_queue<pair<int,char>, vector<pair<int,char>>, less<pair<int,char>>> pq; 
        queue<pair<int,pair<int,char>> > q; 
        for(auto& t : tasks){
            mp[t]++; 
        }
        for(auto& n : mp){

            pq.push({n.second, n.first});
        }
        
        int cycles = 0;
        int time = n; 

        while(!pq.empty() || !q.empty()){
            cycles++;
            if(!pq.empty()){
                int topFreq = (pq.top()).first;
                char topChar = (pq.top()).second;
                pq.pop();
                if(topFreq > 1){
                    q.push({cycles+n, {topFreq - 1, topChar}}); 
                }
            }
            if(!q.empty() && q.front().first == cycles){
                pair<int,pair<int, char>> fr = q.front();
                q.pop();
                pq.push(fr.second);
            }

        }

        return cycles; 
    }
};
