class Solution {
public:
int maxrowindex(vector<vector<int>> mat, int n, int col){
    int maxvalue=INT_MIN;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxvalue) {
            maxvalue=mat[i][col];
        index=i;
        }
     
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int peakelementrowindex =
                maxrowindex(mat,n,mid);
            int left = mid - 1 >= 0 ? mat[peakelementrowindex][mid - 1] : -1;
            int right = mid + 1 < m ? mat[peakelementrowindex][mid + 1] : -1;
            if (mat[peakelementrowindex][mid] > left &&
                mat[peakelementrowindex][mid] > right) {
                return {peakelementrowindex, mid};
            }

            else if (mat[peakelementrowindex][mid] < left)
                high = mid - 1;

            else
                low = mid + 1;
        }
        return{-1,-1};
        
        }
    };