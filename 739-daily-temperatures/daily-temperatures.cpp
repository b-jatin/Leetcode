class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){// storing index pf elements which are in monotonic decreasing order
            while(!st.empty()&& temperatures[st.top()]<temperatures[i]){ 
                ans[st.top()]=i-st.top();// once a greater element is found pop all the lesser elements while 
                st.pop();                // updating their result index to i(larger element)- top index then pop
            }
            st.push(i);// push current element
        }
        return ans;
    }
};