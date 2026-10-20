class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int n : stones){
            heap.push(n);
        }
        while(heap.size() > 0){
            if(heap.size() == 1) return heap.top();
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if(x > y){
                heap.push(x-y);
            }

        }
        return 0;     
    }

};
