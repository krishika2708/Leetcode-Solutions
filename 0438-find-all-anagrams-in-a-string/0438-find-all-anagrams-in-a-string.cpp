class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>ans;
        vector<int>need(26,0);
        vector<int>window(26,0);
        int left=0;
        int right=0;
        if(p.size()>s.size())return ans;
    for(auto c:p){
        need[c-'a']++;
    }
    while(right<n){
            window[s[right]-'a']++;
            if(right-left+1>p.size()){
                window[s[left]-'a']--;
                left++;
            }
            if(right-left+1==p.size()){
                if(need==window) ans.push_back(left);
            }
            right++;
    }
            return ans;
    }
};