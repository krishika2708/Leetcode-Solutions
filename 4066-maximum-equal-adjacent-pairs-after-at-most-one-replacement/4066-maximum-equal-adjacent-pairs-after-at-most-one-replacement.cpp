class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        int base=0;
        map<pair<int,int>,int>cnt;
        for(int i=0;i<n-1;i++){
            int x=nums[i];
            int y=nums[i+1];
            if(x==y){base++;}
            else{
                cnt[{x,y}]++;
                 cnt[{y,x}]++;
            }
        }
        int ans=base;
        for(auto&[p,c]:cnt){
            int x=p.first;
            int y=p.second;
            ans=max(ans,base+c);
        }
        return ans;
    }
};