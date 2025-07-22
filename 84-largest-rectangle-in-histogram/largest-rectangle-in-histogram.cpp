class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++){  //computing left smallest bar for each index
            while(!st.empty()&& heights[st.top()]>=heights[i]){// pop left bars which are greater than current
                st.pop();
            }
            if(st.empty())left[i]=0;//no smaller bar then no boundary
            else{
                left[i]=st.top()+1; //left boundary
            }
            st.push(i); 
        }
        while(!st.empty())st.pop(); //emptying stack
        for(int i=n-1;i>=0;i--){  //computing right smallest bar for each index
            while(!st.empty()&& heights[st.top()]>=heights[i]){// pop left bars which are greater than current
                st.pop();
            }
            if(st.empty())right[i]=n-1;
            else{
                right[i]=st.top()-1;
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};