class Solution {
public:
 bool possible(vector<int>&bloomDay, int day,int m, int k){
            int n=bloomDay.size();
            int count=0;
            int noofbouquet=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=day)  {
                    count++;
                }     
                else{
                    noofbouquet+=count/k;
                    count=0;
                }     
            }
             noofbouquet+=count/k;
             if( noofbouquet>=m)return true;
             else return false;
        }
        int mini(vector<int>&bloomDay){
            int minimum=INT_MAX;
            int n=bloomDay.size();
            for(int i=0;i<n;i++){
                minimum=min(minimum,bloomDay[i]);
            }
            return minimum;
        }
        int maxi(vector<int>&bloomDay){
            int maximum=INT_MIN;
            int n=bloomDay.size();
            for(int i=0;i<n;i++){
                maximum=max(maximum,bloomDay[i]);
            }
            return maximum;
        }
        
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(bloomDay.size()<val) return -1;
       int low=mini(bloomDay);
       int high=maxi(bloomDay);
       while(low<=high){
        int mid=low+(high-low)/2;
                if(possible(bloomDay,mid,m,k)){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
       }
       return low;
    }
};