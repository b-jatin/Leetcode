class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(maxHeap.empty()|| maxHeap.top()>num)
         maxHeap.push(num);
         else
         minHeap.push(num);

         if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
         }
         else if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
         }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            if(minHeap.size()==0)
            return 0;
            else
            return double(minHeap.top() + maxHeap.top())/2.0;
        }
        else{
            return (maxHeap.size()>minHeap.size())?maxHeap.top(): minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */