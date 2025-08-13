class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> um;
        vector<int> res(nums1.size(),-1);
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n2;i++){ // storing NGE of each element of nums2 in map
            int element =nums2[i];
            while(!st.empty() && st.top()<element ){
                um[st.top()]=element;
                st.pop();   
            }
            st.push(element);
        }
        for(int i=0;i<n1;i++){
            if(um.find(nums1[i])!=um.end()){
                res[i]=um[nums1[i]];
            }
        }
        return res;
    }
};