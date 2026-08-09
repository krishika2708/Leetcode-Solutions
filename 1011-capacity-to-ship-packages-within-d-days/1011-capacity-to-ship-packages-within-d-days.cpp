class Solution {
public:
    int sum(vector<int>& weights) {
        int s = 0;
        for (int i = 0; i < weights.size(); i++) {
            s = s + weights[i];
        }
        return s;
    }
    int reqdays(vector<int>& weights, int cap) {
        int load = 0;
        int d = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i]+load > cap) {
                d++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = sum(weights);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (reqdays(weights,mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};