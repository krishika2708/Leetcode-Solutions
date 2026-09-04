class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorr=x^y;
        int cnt=0;
        while(xorr){
            xorr=xorr&(xorr-1);
            cnt++;
        }
        return cnt;
    }
};