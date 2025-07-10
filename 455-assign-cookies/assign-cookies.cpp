class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int clen=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0; // l iterates through children and r iterates through cookies
        while(l<n && r<clen){
            if(s[r]>=g[l]){
                l++;
                r++;
            }
            else
            r++;

        }
        return l;

        
    }
};