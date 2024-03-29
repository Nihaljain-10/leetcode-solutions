class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int len=0;
        vector<int>mp(256,-1);
       while(r<n){
           if(mp[s[r]]!=-1)l=max(l,mp[s[r]]+1);
           mp[s[r]]=r;
           len=max(len,r-l+1);
           r++;
        }
        return len;
    }
};