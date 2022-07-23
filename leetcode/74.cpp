
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //变一维即可
        int n=matrix.size()*matrix[0].size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            int x=mid/int(matrix[0].size());
            int y=mid%int(matrix[0].size());
            if(matrix[x][y]<target)l=mid+1;
            else r=mid;
        }
            int x=l/int(matrix[0].size());
            int y=l%int(matrix[0].size());
        if(matrix[x][y]==target)return 1;
        return false;
        }
};