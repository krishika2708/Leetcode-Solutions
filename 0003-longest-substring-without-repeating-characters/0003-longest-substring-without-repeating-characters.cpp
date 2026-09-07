class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int n=s.size();
        int maxlen=0;
        vector<int>array(256,-1);
        int l=0;
        int r=0;
        while(r<n){
            if(array[s[r]]!=-1){
                if(array[s[r]]>=l) l=array[s[r]]+1;
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            array[s[r]]=r;
            r++;

        }
        return maxlen;
    }
};