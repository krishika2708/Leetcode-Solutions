class Solution {
public:
const long long MOD=1000000007;
long long power(long long x, long long k){
    if(k==0) return 1;
    long long half=power(x,k/2);
    half=(half*half)%MOD;
    if(k%2==0) return half;
    else return (x*half)%MOD;
}
    int countGoodNumbers(long long n) {
        long long evenindices=(n+1)/2;
        long long oddindices=n/2;
        return(power(5,evenindices)*power(4,oddindices))% MOD;
    }
};