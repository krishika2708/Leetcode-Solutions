
class Solution {
public:
    int maxi(vector<int>& piles) {
        int n = piles.size();
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, piles[i]);
        }
        return maximum;
    }
    long long totalhours(vector<int>& piles, int hourly) {
        long long total = 0;

        for (int i = 0; i < piles.size(); i++) {
            total += ceil((double)piles[i] / hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxi(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalhrs = totalhours(piles, mid);

            if (totalhrs <= h) {

                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};