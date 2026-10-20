class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int& n : stones){
            heap.push(n);
        }
        while(heap.size() > 1){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if(x > y){
                heap.push(x-y);
            }

        }
        heap.push(0);
        return heap.top();     
    }

};
