class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for(auto i: stones){
            pq.push(i);
        }
        int y=pq.top(),x=0;
        pq.pop();
        while(pq.size()>=1){
            x=pq.top();
            pq.pop();
            if(x==y){
                if(pq.size()>=1){
                y=pq.top();
                pq.pop();
                }
                else
                    return 0;
            }
            else{
                pq.push(y-x);
                if(pq.size()>=1){
                y=pq.top();
                pq.pop();
                }
                else
                    break;
                
            }
        }
        return pq.top();

    }
};