class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
         vector<int> res;
        deque<int> dq;
        //striver solution
        for (int i = 0; i < nums.size(); i++) {//storing indexes in deque. pushing from back(monotonic decreasing)
            if(!dq.empty() && dq.front()<=i-k)  // maintaining k elements window(removing the unwanted elements)
                dq.pop_front();
            while(!dq.empty()&& nums[dq.back()]<=nums[i]) // if the back element is less than current element pop
                dq.pop_back();
            dq.push_back(i); // push one element at each iteration
            if(i>=k-1)
            res.push_back(nums[dq.front()]); // add the max element of each window
        }

        return res;
    }
};