class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans=strs[0];
        for(int i=1;i<n;i++){
            while(strs[i].find(ans)!=0){
                ans.pop_back();
            }
            }
        return ans;
    }
};